// steal.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam;
	int sp, dp;

	if( environment(me)->query("no_steal")
	||  environment(me)->query("no_fight")
	||  environment(me)->query("fight_room")) 
		return notify_fail("这里禁止行窃。\n");

	if( me->query_temp("stealing") )
		return notify_fail("你已经在找机会下手了！\n");

	if (me->is_busy())
		return notify_fail("你现在正忙，没有时间。\n");

	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 )
		return notify_fail("指令格式：steal <物品> from <人物>\n");

	victim = present(who, environment(me));

	if( !victim || victim==me) 
		return notify_fail("你想行窃的对象不在这里。\n");
	
	if( !victim->is_character() || victim->is_corpse())
		return notify_fail("看清楚一点，那并不是活物。\n");

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("玩家不能偷巫师身上的东西。\n");

	if(!victim->query("can_speak"))
		return notify_fail("你找错对象了吧？\n");

	if(victim->query_temp("sleeping"))
		return notify_fail("趁人睡觉想偷东西？你的良心何在啊？\n");

	if((int)victim->query("age") <= 18 && userp(victim))
		return notify_fail("偷小孩子身上的东西，你羞不羞？\n");

	if( !ob = present(what, victim)){
		object *inv;
		inv = all_inventory(victim);
	if( !sizeof(inv) )
		return notify_fail( victim->name() + "身上看起来没有什麽值钱的东西好偷。\n");
	ob = inv[random(sizeof(inv))];
	}

	sp = (int)me->query_skill("stealing") * 5 + (int)me->query("kar") * 2 - (int)me->query("thief") * 20;

	if ( (myfam = me->query("family")) && myfam["family_name"] == "丐帮" )
		sp = (int)me->query_skill("stealing") * 10 + (int)me->query("kar") * 5- (int)me->query("thief") * 20;
	
	if(objectp(me->query_temp("weapon"))) sp /= 10;
	if( sp < 1 ) sp = 1;

	if( me->is_fighting()){
		sp /= 2;
		if(!me->is_busy()) me->start_busy(3);
	}
	
	dp = (int)victim->query("jing") * 2 + (int)ob->weight()/25;
	if( victim->is_fighting() ) dp *= 10;
	if( ob->query("equipped") ) dp *= 10;

	write("你不动声色地慢慢靠近" + victim->name() + "，等待机会下手 ...\n\n");

	me->set_temp("stealing", 1);
	call_out( "compelete_steal", 3, me, victim, ob, sp, dp);
	return 1;
}

private void compelete_steal(object me, object victim, object ob, int sp, int dp)
{
	mapping myfam;
	int steal_level;

	if(!me) return;
	me->delete_temp("stealing");

	if (!victim || !ob) return;
	if( environment(victim) != environment(me)){
		tell_object(me, "太可惜了，你下手的目标已经走了。\n");
		return;
	}

	if( !living(victim) || (random(sp+dp) > dp) ){
		if (victim->query_temp("is_riding") == ob->name())
		{
			tell_object(me, "你摸到了" + victim->name() + "的坐骑" + ob->name() +
				    "，想了想，还是老老实实的放了手。\n");
			return;
		}

		if (ob->query("no_steal") || ob->query("no_get") || ob->query("no_beg"))
		{
			tell_object(me, "你摸到一" + ob->query("unit") + ob->name() +
				    "，可是你突然作贼心虚，居然不敢下手，真是可惜了。\n");
			return;
		}

		if (sizeof(all_inventory(me)) >= 50)
		{
			tell_object(me, "眼看你就要得手，可惜身上的东西太多，实在拿不了了。\n");
			ob->move(environment(me));
			return;
		}

		if (! ob->move(me))
		{
			tell_object(me, "你摸到一" + ob->query("unit") + ob->name() +
				    "，可是对你而言太重了，不得不放弃。\n");
			return;
		}

		tell_object(me,HIW"嘿！得手了！\n\n" NOR);
		tell_object(me,"你成功地偷到一" + ob->query("unit") + ob->name() + "！\n");
	
		if(random(10) == 3)
			CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("我亲眼看到%s从%s身上偷了一%s%s啦！",
				me->name(),victim->name(),ob->query("unit"),ob->name()));
	
		steal_level = (int)me->query_skill("stealing",1);

		if ((int)me->query("combat_exp") > (steal_level*steal_level*steal_level/10) )
		me->improve_skill("stealing", random(me->query("int")));

		if ( (myfam = me->query("family")) && myfam["family_name"] == "丐帮" ){
			if(((int)me->query("potential") - (int)me->query("learned_points") < 100))
			me->add("potential",1);
			if(!me->is_busy()) me->start_busy(2);
			me->add("thief", 1);
			me->add("jing",-10);
			me->add("combat_exp",1);
		}

	if( random(sp) < dp/2 )
		message("vision", "你看到" + me->name() + "鬼鬼祟祟地从"+ victim->name() + "身上偷走了一" + ob->query("unit")
		+ ob->name() + "！\n", environment(me), ({ me, victim }) );

	}
	else{
		if( random(sp) > dp/2 ){
			tell_object(me, victim->name() + "不经意地一转头，你急忙将手缩了回去！还好，没有被发现。\n");
			return;
		}
	      
		tell_object(me, HIR "糟糕！你失手了！\n\n" NOR);
		message_vision("$N一回头，正好发现$n的手正抓着$P身上的" + ob->name() + "！\n\n"+ "$N喝道：「干什么！」\n\n", victim, me);
	
		if (userp(victim) && userp(me))
		{
			message_vision("$N狠狠的往$n的屁股踢了一脚，痛得$n捂着屁股呜呜直叫。\n",
			victim, me);
		} else
		{
			victim->kill_ob(me);
			me->fight_ob(victim);
		}
	
		if(!me->is_busy()) me->start_busy(3);
		me->add("thief", 1);
		me->add("jing",-10);

	}

}

int help(object me)
{
write(@HELP
指令格式 : steal <某物> from <某人>

这个指令让你有机会偷到他人身上的东西。成功了, 当然你就能获得
该样物品。可是, 马有失蹄, 人总有失风的时候, 当你失败时当然就
得付出代价, 至於是什么代价......靠你自己去发掘罗。
HELP
	);
	return 1;
}

