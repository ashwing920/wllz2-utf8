// recommend.c
// 推举帮主

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object ob;

	if(!arg)
		return notify_fail("你要推举谁为帮主？\n");

	if(arg == "?"){
		REC_D->query_vote(me->query("id"));
		return 1;
	}

	ob = present(arg, environment(me));
	if(!ob) ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) 
		return notify_fail("你要推举谁为帮主？\n");

	if(ob == me && !wizardp(me))
		return notify_fail("你不能投票推举自己。\n");

	if((int)me->query("weiwang") < 5000)
		return notify_fail("你的威望不足，无权推举帮主。\n");
	
	if((int)me->query("recommend") > 4)
		return notify_fail("你的投票推举权力已经用完了。\n");

	REC_D->add_vote(ob->query("id"),me->query("id"));
	me->add("recommend",1);
	me->add("weiwang",-500);
	return 1;
}
int help(object me)
{
	write(@HELP

指令格式 : recommend ?		查询当前关于自己的投票。
	   recommend <玩家id>   投票推举游戏玩家为帮主。

投票推举帮主需要 5000 点江湖威望，每次推举将扣减 500 点江湖威望，
并且减少一次投票推举的权力，每一个玩家的投票推举权力只有五次。

HELP
);
	return 1;
}

