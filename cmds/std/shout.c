// shout.c

inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string arg)
{
	if(me->ban_say()) return 0;

	if(!arg || arg == "" )
		return notify_fail("你想要大叫什么？\n");

	if(!wizardp(me) && me->query_condition("no_speak"))
		return notify_fail("你支支吾吾的，半天也说不出句话来。\n");

	if(!wizardp(me) && userp(me)) {
		if((int)me->query("mud_age") <= 345600 )
			return notify_fail("小孩子家，叫什么叫？\n");

		if((int)me->query("max_neili") < 2000)
			return notify_fail("你的内力修为不够，无法使用 shout 指令进行传话。\n");

		if((int)me->query("jingli") < 500)
			return notify_fail("你的精力不足，无法使用 shout 指令进行传话。\n");

		if((int)me->query("neili") < 600)
			return notify_fail("你的内力不足。\n");

		me->add("neili",- (int)me->query("neili") / 3);
		me->add("jingli",-500);

		shout(HIW+me->name() + "("+ capitalize(me->query("id")) +")纵声长啸：" + arg + "\n"NOR);
		write(HIW+"你纵声长啸：" + arg + "\n"NOR);
	}
	else {
		shout(HIW+me->name() + "("+ capitalize(me->query("id")) +")纵声长啸：" + convert_color(arg) + NOR"\n"NOR);
		write(HIW+"你纵声长啸："+ convert_color(arg) + NOR"\n"NOR);
	}
	return 1;
}
int help(object me)
{
	write(@HELP

指令格式 : shout <讯息>

这个指令让你将 <讯息> 传送出去, 所有正在游戏中的人都会听见你的话。
你必须年满十八岁并拥有至少点1000点内力支持！每次需要花费 500的点精
力！
HELP
);
	return 1;
}
