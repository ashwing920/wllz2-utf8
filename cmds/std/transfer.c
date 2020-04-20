 // transfer.c
#include <ansi.h>
#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int amount;

	seteuid(getuid());
	
	if( me->is_fighting() )
		return notify_fail("战斗中不能练转移潜能，会走火入魔。\n");

	if( me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if( !arg || !sscanf(arg, "%d", amount) )
		amount = 30;

	if( amount < 2 ) return notify_fail("你最少要转移 2 点潜能。\n");

	if(((int)me->query("potential")-(int)me->query("learned_points")) < amount )
		return notify_fail("你没有这么多的潜能来转移。\n");

	if( (int)me->query("qi") < 30 )
		return notify_fail("你现在精神状况太差了，无法凝神专一！\n");
	me->receive_damage("qi", 30);
	me->add("potential",-amount);
	me->add("combat_exp", amount/2 );
	write("你把「"HIY + amount+ NOR"」点潜能转换成了「"HIM + amount/2 + NOR"」点的经验。\n");
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : transfer [<耗费「潜能」的量，预设值 30>]

这个命令可以把你的潜能化为经验。比率是2/1.
也就是 2 点潜能 换 1 点 经验
HELP
	);
	return 1;
}
 

