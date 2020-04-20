// murong-zhang.c - 慕蓉掌法

inherit SKILL;

mapping *action = ({
([      "action" : "$N向前踏上一步，一招「恒山掌法」，掌势如风，击向$n的$l要害",
	"force"         : 80,
	"dodge"         : 5,
	"parry"         : 5,
	"damage"        : 5,
	"lvl"           : 0,
	"skill_name"    : "恒山掌法",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N双足轻点，一招「衡山掌法」，双手狂风骤雨般地向$n的$l击去",
	"force"         : 100,
	"dodge"         : 5,
	"parry"         : 5,
	"damage"        : 10,
	"lvl"           : 10,
	"skill_name"    : "衡山掌法",
	"damage_type"   : "瘀伤"
]),
([      "action" : "只见$N双手如风，一招「泰山掌法」，斜斜地划向$n的$l要害",
	"force"         : 120,
	"dodge"         : 10,
	"parry"         : 10,
	"damage"        : 20,
	"lvl"           : 20,
	"skill_name"    : "泰山剑法",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N身形一转，一招「嵩山掌法」，双掌挟呼呼风声迅猛击向$n的$l",
	"force"         : 140,
	"dodge"         : 20,
	"parry"         : 20,
	"damage"        : 30,
	"lvl"           : 30,
	"skill_name"    : "嵩山掌法",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N纵身一跃，手中$w一招「华山掌法」，幻成一条疾光击向$n的$l",
	"force"         : 160,
	"dodge"         : 30,
	"parry"         : 30,
	"damage"        : 40,
	"lvl"           : 40,
	"skill_name"    : "华山掌法",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「昆仑掌法」，掌势如风，双手直击$n的$l",
	"force"         : 180,
	"dodge"         : 40,
	"parry"         : 40,
	"damage"        : 50,
	"lvl"           : 50,
	"skill_name"    : "昆仑掌法",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N身形一转，一招「峨眉掌法」，掌风不定，招招击向$n的$l要害",
	"force"         : 200,
	"dodge"         : 50,
	"parry"         : 50,
	"damage"        : 60,
	"lvl"           : 60,
	"skill_name"    : "峨眉掌法",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「逍遥掌法」，$n只觉得眼前一花，全身被笼罩在一团掌风之中",
	"force"         : 220,
	"dodge"         : 60,
	"parry"         : 60,
	"damage"        : 80,
	"lvl"           : 70,
	"skill_name"    : "逍遥掌法",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N错步上前，一招「少林掌法」，拳意若有若无，淡淡地向$n的$l击去",
	"force"         : 240,
	"dodge"         : 70,
	"parry"         : 70,
	"damage"        : 100,
	"lvl"           : 80,
	"skill_name"    : "少林掌法",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「武当掌法」，纵身飘开数尺，运发真气，双手中遥摇指向$n的$l",
	"force"         : 260,
	"dodge"         : 80,
	"parry"         : 80,
	"damage"        : 120,
	"lvl"           : 100,
	"skill_name"    : "武当掌法",
	"damage_type"   : "瘀伤"
]),
});

int valid_enable(string usage) { return (usage == "unarmed") || (usage == "parry") || (usage == "strike" ); }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练慕容掌法必须空手。\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力不够。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"]) return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("murong-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"]) return action[random(i)];
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练慕容掌法必须空手。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力不够练慕蓉掌法。\n");
	me->receive_damage("qi", 35);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"murong-zhang/" + action;
}
