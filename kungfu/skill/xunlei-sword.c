// xunlei-sword.c 迅雷剑

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([  
	"action":"$N使一式「潮泛银海」，手中$w疾挽，漫天寒光，隐夹风雷之声，闪电般狂涌向$n的$l",
	"force" : 120,
	"lvl" : 0,
	"skill_name" :"潮泛银海" ,
	"damage_type":  "割伤"
]),
([  
	"action":"$N错步上前，使出「银雨飞花」，手中$w登时剑芒暴射，宛如漫天瑞雪飞洒向$n的$l",
	"force" : 140,
	"lvl" : 20,
	"skill_name" : "银雨飞花",
	"damage_type":  "割伤"
]),
([  
	"action":"$N手中$w一抖，一招「花影滨飞」，$w犹如狂风扫落叶般急攻向$n的$l",
	"force" : 160,
	"lvl" : 34,
	"skill_name" : "花影滨飞",
	"damage_type":  "割伤"
]),
([  
	"action":"$N手中$w锵啷啷长吟一声，一式「神雕找食」，$w头上脚下洒攻而下，攻势之疾，无以伦比向$n的$l",
	"force" : 180,
	"lvl" : 47,
	"skill_name" : "神雕找食",
	"damage_type":  "刺伤"
]),
([  
	"action":"$N一式「西风倒卷」，手中$w将剑自下拖上，端的无比毒辣使$n难断虚实，无可躲避",
	"force" : 220,
	"lvl" : 60,
	"skill_name" : "西风倒卷",
	"damage_type":  "刺伤"
]),
([  
	"action":"$N手中$w,一式「天罗地网」，仿佛一面无形的黑网向$n的$l斜斜击出",
	"force" : 260,
	"lvl" : 80,
	"skill_name" :"天罗地网",
	"damage_type":  "刺伤"
]),
([  
	"action":"$N一式「日月失色」，$w银光万道，如江河倒泻，剑芒绵绵无尽向$n的胸口递去",
	"force" : 380,
	"lvl" : 110,
	"skill_name" : "日月失色",
	"damage_type":  "刺伤"
]),
([  
	"action":"$N一式「金针渡劫」，$w形神合一，把全部真气贯注剑身之上，快如天光乍闪向$n刺去",
	"force" : 380,
	"lvl" : 150,
	"skill_name" :"金针渡劫",
	"damage_type":  "刺伤"
])
});
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你必须先弄把剑才能学迅雷剑法。\n");
	if(me->query_skill("sword", 1) <= me->query_skill("xunlei-sword",1))
		return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	if(level >= action[i]["lvl"])
		return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("xunlei-sword",1);
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"]) return action[random(i)];
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练迅雷剑。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不足以练迅雷剑。\n");
	me->receive_damage("qi", 25);
	me->add("neili",-20);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"xunlei-sword/" + action;
}
