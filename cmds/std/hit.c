// hit.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj,env;

	env = environment(me);

	if( env->query("no_fight") || env->query("restrict_action"))
		return notify_fail("这里禁止战斗。\n");

	if(env->query("fight_room"))
		return notify_fail("这里不能使用这个命令。\n");

	if(!arg || !objectp(obj = present(arg, env)))
		return notify_fail("你想攻击谁？\n");

	if( obj->query("no_kill"))
		return notify_fail("你不能攻击这个人！\n");

	if( !obj->is_character() )
		return notify_fail("看清楚一点，那并不是生物。\n");

	if( obj->is_fighting(me) )
		return notify_fail("加油！加油！加油！\n");

	if( me->query_temp("hitting") )
		return notify_fail("加油！加油！加油！\n");

	if(obj->query_temp("sleeping"))
		return notify_fail("趁人家睡觉的时候下手，你怎么那么卑鄙啊？\n");

	if(obj->is_fight_npc())
		return notify_fail("请使用 fight 指令！\n");

	if(obj==me)
		return notify_fail("打自己？别这么想不开。\n");

	if(userp(obj) && (int)obj->query("age") <= 18 )
		return notify_fail("连小孩子都欺负，太过分了点吧？！\n");

	if( userp(obj) && (int)me->query("age") <= 18)
		return notify_fail("唉！你不要命了吗？\n");

	if (!living(obj)) 
		return notify_fail(obj->name()+"已经无法还手了！\n");
	
	if(me->query_temp("hitting") == obj)
		return notify_fail("你正在和"+ obj->name()+"生死相搏呢！\n");

	if( userp(obj)) {
		message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj);
		me->set_temp("hitting",obj);
		if(!me->query_temp("first_kill/"+obj->query("id"))) me->set_temp("first_kill/"+obj->query("id"), 1);
		if (!me->is_busy()) me->start_busy(1);
		remove_call_out("do_hit");
		call_out("do_hit",1,me,obj);
		return 1;
	}
	if( obj->query("can_speak"))
		message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj);
	else
		message_vision("\n$N大喝一声，开始对$n发动攻击！\n\n", me, obj);

	notify_fail("你无从下手。\n");
	switch (obj->accept_hit(me))
	{
	case 0:
		return 0;
	case -1:
		return 1;
	default:
	}

	me->fight_ob(obj);
	return 1;
}
void do_hit(object me, object obj)
{
	if(!obj || environment(me) != environment(obj)) {
		me->delete_temp("hitting");
		return;
	}
	if(userp(obj)){
		write_file("/log/static/ATTEMP_HIT",sprintf("[%s]%s[%s]试图袭击%s[%s]\n",
			ctime(time()),me->name(1),me->query("id"),obj->name(1),obj->query("id")));
	}

	if(objectp(present(obj, environment(me)))) {
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon"),2);
		COMBAT_D->do_attack(obj, me, obj->query_temp("weapon"),1);
		me->delete_temp("hitting");
		return;
	}
	me->delete_temp("hitting");
	return;

}

int help(object me)
{
  write(@HELP
指令格式 : hit <人物>

这个指令让你直接向一个人物「进招」。这种形式的战斗是即时的，只要玩家一
敲这个命令，战斗就会开始，直到某一方受伤50% 以上为止。这个指令对那些不
喜欢fight的NPC很有用，因为很多时候你的比武要求会被拒绝。

其他相关指令: fight, kill

而在对玩家使用 hit 指令的时候，有着一定的区别。不可以对小于16岁的玩家使
用 hit 指令，小于16岁的玩家也不可以对其他玩家使用 hit 指令。因为新玩家
始终是受保护的！


HELP
	);
	return 1;
}
