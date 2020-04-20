// train.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	int sp, dp;
	int cost, train_level;

	seteuid(getuid());

	if( me->is_fighting())
		return notify_fail("战斗中无法对野兽进行驯服。\n");

	if((int)me->query_skill("training",1) < 10 )
		return notify_fail("你的驭兽术还不纯熟，无法训练野兽！\n");

	if(!arg)
		return notify_fail("你要训练什么野兽？\n");

	if( !objectp(ob = present(arg, environment(me)) ))
		return notify_fail("这里没有这只野兽吧？\n");

	if( userp(ob) 
	|| ((string)ob->query("race") != "野兽" && (string)ob->query("race") != "蛇类" 
	&& (string)ob->query("race") != "飞禽"  && (string)ob->query("race") != "游鱼" 
	&& (string)ob->query("race") != "昆虫"  && (string)ob->query("race") != "家畜")) 
		return notify_fail("你只能驯服野动物。\n");

	if(ob->is_fighting())
		return notify_fail(ob->name() + "正在战斗，你的驯服毫无作用。\n");

	if( ob->query_temp("owner") &&
	( ob->query_temp("owner") == me->query("id") ))
		return notify_fail(ob->name() + "就是你驯服过的了。\n");

	if( ob->query_temp("owner") &&
	( ob->query_temp("owner") != me->query("id") ))
		return notify_fail(ob->name() + "早已经被人家驯服了。\n");

	if ( ob == me )
		return notify_fail("你不能驯服自己。\n");

	if (!living(ob)) 
		return notify_fail(ob->query("name")+"已经不醒人事，驭兽术好象对它毫无作用。\n");

	cost = (int)me->query("max_jing")/(me->query_skill("training",1)/10) - 10;

	if((int)me->query("jing") <= cost )
		return notify_fail("现在你太累了，无法使用驭兽术。\n");

	message_vision("只见$N冲着"+ob->name()+"手脚乱摆，口中似对它轻轻细语。\n\n",me);

	sp = (int)me->query_skill("training",1) + me->query("int");
	dp = (int)ob->query("combat_exp")/100;
	
	if ( random(sp) < random(dp)/2 )
	{
		ob->kill_ob(me);
		return notify_fail( "你驭兽术不精，那东西野性不泯，冲着你就窜了过来！\n");
	}
	if ( cost > 0) me->add("jing", -cost );
	if ( cost < 0) me->add("jing",  cost );
	message_vision("顿时"+ob->name()+"冲着$N摇了摇尾巴，很温驯的样子。\n\n",me);

	train_level = (int)me->query_skill("training", 1);
	if ( (int)me->query("combat_exp") > (train_level*train_level*train_level)/10)
	{
		me->improve_skill("training", random((int)me->query("int")));
	}

	ob->set("attitude", "peace");
	ob->remove_all_enemy(1);
	ob->set_temp("owner",me->query("id"));
	ob->set_temp("ownername",me->query("name"));
	if( (strsrch(ob->query("name"), "马") >= 0) ||
	   ( strsrch(ob->query("name"), "驴") >= 0) ||
	   ( strsrch(ob->query("name"), "骡") >= 0) ||
	   ( strsrch(ob->query("name"), "驼") >= 0) ||
	   ( strsrch(ob->query("name"), "牛") >= 0) ||
	   ( strsrch(ob->query("name"), "象") >= 0) ||
	   ( strsrch(ob->query("name"), "狮") >= 0) ||
	   ( strsrch(ob->query("name"), "虎") >= 0) ||
	   ( strsrch(ob->query("name"), "豹") >= 0) ||
	   ( strsrch(ob->query("name"), "鹿") >= 0) ||
	   ( strsrch(ob->query("name"), "鲨") >= 0) ||
	   ( strsrch(ob->query("name"), "雕") >= 0))
	
	ob->set("horse_prop/max_life",train_level / 10);
	ob->set("horse_prop/life",10);
	ob->set("ridable",1);
	me->remove_all_enemy();
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : train <动物>

此指令可用于驯化某动物。对于已经驯服的动物，可以进行下述指令：

基本指令：
	come <动物名>:            让动物跟随主人行动。
	stay:                     停止动物的跟随状态。
	attack <某人>:            让动物攻击敌人。
	stop <动物名>:            让动物停止对人的攻击。
	release:                  结束主奴状态，将动物放离。

特殊指令：（只对某些动物适用）
	qi(ride) <动物名>:        骑，如骑马，虎，雕，鲨等。
	xia(unride) <动物名>:     下，离开坐骑。
	wei(feed) <动物名>:       替动物喂食。
	yin <动物名>:             给动物饮水。

HELP
	);
	return 1;
}
