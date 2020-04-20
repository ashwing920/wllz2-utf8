// bosi-guaizhao.c - 波斯怪招

inherit SKILL;

mapping *action = ({
([  	"action" : "$N一招「波斯怪招」，气凝丹田，$N左掌从奇异的角度向$n的$l袭去",
	"force"         : 80,
	"dodge"         : 5,
	"lvl"           : 0,
	"skill_name"    : "波斯怪招",
	"damage_type"   : "瘀伤"
]),
([  	"action" : "$N施出「波斯怪招」，双拳一振，一股力道排山倒海般向$n的$l推了过去",
	"force"         : 100,
	"dodge"         : 5,
	"lvl"           : 10,
	"skill_name"    : "波斯怪招",
	"damage_type"   : "瘀伤"
]),
([  	"action" : "$N一招「波斯怪招」，大吼一声，身形转动，忽然双手击向$n的$l",
	"force"         : 120,
	"dodge"         : 10,
	"lvl"           : 20,
	"skill_name"    : "波斯怪招",
	"damage_type"   : "瘀伤"
]),
([  	"action" : "$N施出「波斯怪招」，左手招架，右手却突然从让人难料的角度向$n打去",
	"force"         : 140,
	"dodge"         : 20,
	"lvl"           : 30,
	"skill_name"    : "损心伤肺摧肝肠",
	"damage_type"   : "瘀伤"
]),
([  	"action" : "$N一招「波斯怪招」，在地上滚动，右手却突然从斜逢中打出，直击向$n的$l",
	"force"         : 160,
	"dodge"         : 30,
	"lvl"           : 40,
	"skill_name"    : "波斯怪招",
	"damage_type"   : "瘀伤"
]),
([  	"action" : "$N一招「波斯怪招」，掌势如风，奇招叠出，双手不断地从别人意想不到的方向打向$n",
	"force"         : 180,
	"dodge"         : 40,
	"lvl"           : 50,
	"skill_name"    : "波斯怪招",
	"damage_type"   : "瘀伤"
]),
([  	"action" : "$N身形一转，一招「波斯怪招」，真是见所未见，闻所未闻，竟可以从不可能的方向突袭$n",
	"force"         : 200,
	"dodge"         : 50,
	"lvl"           : 60,
	"skill_name"    : "波斯怪招",
	"damage_type"   : "瘀伤"
]),
([  	"action" : "$N一招「波斯怪招」，$n只觉得完全出乎意料，眼前一花，全身被笼罩在一团掌风之中",
	"force"         : 220,
	"dodge"         : 60,
	"lvl"           : 70,
	"skill_name"    : "波斯怪招",
	"damage_type"   : "瘀伤"
]),
([  	"action" : "$N错步上前，一招「波斯怪招」，拳意若有若无，淡淡地向$n的$l击去",
	"force"         : 240,
	"dodge"         : 70,
	"lvl"           : 80,
	"skill_name"    : "波斯怪招",
	"damage_type"   : "瘀伤"
]),
([  	"action" : "$N一招「波斯怪招」，纵身飘开数尺，运发真气，双手中遥摇指向$n的$l",
	"force"         : 260,
	"dodge"         : 80,
	"lvl"           : 100,
	"skill_name"    : "波斯怪招",
	"damage_type"   : "瘀伤"
]),
});

int valid_enable(string usage) { return (usage == "unarmed") || (usage == "parry"); }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练波斯怪招必须空手。\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力不够。\n");
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
	level   = (int) me->query_skill("bosi-guaizhao",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
		return action[NewRandom(i, 5, level/5)];

}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
	return notify_fail("练波斯怪招必须空手。\n");
	if ((int)me->query("qi") < 50)
	return notify_fail("你的体力不够练波斯怪招。\n");
	me->receive_damage("qi",40);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"bosi-guaizhao/" + action;
}
