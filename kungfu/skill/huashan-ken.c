// huashan-ken.c 华山拳法

inherit SKILL;

mapping *action = ({
([	"action":	"$N使一招「云里乾坤」左拳击出，不等招式使老，右拳已从左拳之底穿出，对准$n的$l「呼」地一拳",
	"dodge":   	-40,
	"parry":   	40,
	"damage":	120,
	"skill_name":	"云里乾坤",
	"lvl":		10,
	"damage_type":  "瘀伤"
	]),
([	"action":	"$N左拳突然张开，拳开变掌，直击化为横扫，一招「雾里看花」便往$n的$l招呼过去",
	"dodge":   	-30,
	"parry":   	30,
	"damage":	180,
	"skill_name":	"雾里看花",
	"lvl":		30,
	"damage_type":  "瘀伤"
	]),
([	"action":	"$N两手虎口相对，往内一圈，一招「金鼓齐鸣」往$n的$l击出",
	"dodge":   	-30,
	"parry":   	30,
	"damage":	240,
	"skill_name":	"金鼓齐鸣",
	"lvl":		80,
	"damage_type":  "瘀伤"
	]),
([	"action":	"$N步履一沉，左拳虚晃一招，右拳使出「梅花弄影」击向$n$l",
	"dodge":   	-30,
	"parry":   	30,
	"damage":	150,
	"skill_name":	"梅花弄影",
	"lvl":		120,
	"damage_type":  "瘀伤"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练华山拳法必须空手。\n");
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 )
   return notify_fail("你的体力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 30);
	return 1;
}

