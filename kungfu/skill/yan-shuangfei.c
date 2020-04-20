// yanfly.c 燕双飞
#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
	"$n一个「"+MAG+"比翼双飞"+NOR+"」，随着$N的攻势飘起，从容躲过这一招。\n",
	"$n使出一招「"+MAG+"巧燕穿云"+NOR+"」，猛然纵起丈余，结果$N扑了个空。\n",
	"$n身形一摇，幻出几个人影，一招「"+GRN+"望穿秋水"+NOR+"」躲过了$N的攻势。\n",
	"$n一招「"+BLU+"飞鸟投林"+NOR+"」纵身跃起，倏忽已落至$N身后。\n",
	"$n左一摇，右一晃，一招「"+MAG+"紫燕呢喃"+NOR+"」已轻松闪过。\n",
});

int valid_enable(string usage) 
{ 
	return (usage == "dodge") ;
}
int valid_learn(object me)
{
	if (me->query_skill("dodge", 1) <=me->query_skill("yan-shuangfei", 1))
		return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
	return 1; }
string query_dodge_msg(string limb)
{
		return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
		if( (int)me->query("qi") < 30 )
			return notify_fail("你的体力太差了，不能练燕双飞。\n");
		if (me->query_skill("yan-shuangfei", 1) < 30)
			me->receive_damage("qi", 10);
		me->receive_damage("qi", 20);
		return 1;
}
