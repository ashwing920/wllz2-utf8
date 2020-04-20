// dashou-yin.c 灭仙掌

inherit SKILL;

mapping *action = ({
([      "action" : "$N使出一招「血海狂龙」，双掌直直撞向$n的前胸",
	"skill_name" : "血海狂龙",
	"force" : 100,
	"dodge" : 10,
	"lvl" : 0,
	"damage":50,
	"damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「舍我其谁」，飞身跃起，双手直扑抓向$n的$l",
	"skill_name" : "舍我其谁",
	"force" : 200,
	"dodge" : 50,
	"lvl" : 8,
	"damage":50,
	"damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「傲俾三界」，幻出手影，直抓$n的$l",
	"skill_name" : "傲俾三界",
	"force" : 250,
	"dodge" : 10,
	"lvl" : 16,
	"damage":50,
	"damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「绝天一式」,一掌当头拍向$n的$l",
	"skill_name" : "绝天一式",
	"force" : 300,
	"dodge" : 11,
	"lvl" : 24,
	"damage":50,
	"damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「绝天二式」，一掌直取$n",
	"skill_name" : "绝天二式",
	"force" : 350,
	"dodge" : 12,
	"lvl" : 32,
	"damage":50,
	"damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「绝天三式」，一掌直取$n的$l",
	"skill_name" : "绝天三式",
	"force" : 400,
	"dodge" : 12,
	"lvl" : 40,
	"damage":50,
	"damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「绝天四式」，飞身横跃，双掌前后击出，抓向$n的咽喉",
	"skill_name" : "绝天四式",
	"force" : 450,
	"dodge" : 10,
	"lvl" : 48,
	"damage":100,
	"damage_type" : "瘀伤",
]),
([      "action" : "$N使出一招「绝天式」，顿时一片血影，无数血掌直击$n的$l",
	"skill_name" : "绝天式",
	"force" : 500,
	"dodge" : 20,
	"lvl" : 56,
	"damage":150,
	"damage_type" : "瘀伤",
]),
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry" || usage == "unarmed"; }
int valid_combine(string combo) { return combo=="xue-dao"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练灭仙掌必须空手。\n");

	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("xuehai-mogong", 1) < 20)
		return notify_fail("你的血海魔功火候太浅。\n");

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
		  
	level = (int) me->query_skill("miexian-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练灭仙掌必须空手。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力不够，练不了灭仙掌。\n");
	me->receive_damage("qi", 20);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"miexian-zhang/" + action;
}
