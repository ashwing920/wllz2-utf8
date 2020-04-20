// sun-finger.c 一阳指

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「阳关三叠」，真气自指间喷薄而出，连出三指，快如电闪，点向$n的$l",
	"force" : 100,
	"dodge" : 25,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "阳关三叠",
	"damage_type" : "内伤"
]),
([	"action" : "$N身形一转，一步跨到$n身后。$n急忙转身，$N又如闪电般跃回，\n一式「鲁阳返日」，右手食指疾出，指向$n的$l",
	"force" : 120,
	"dodge" : 25,
	"damage": 20,
	"lvl" : 20,
	"skill_name" : "鲁阳返日",
	"damage_type" : "内伤"
]),
([	"action" : "$N向左踏出一步，左手轻扬，右手食指挟着雄浑内力疾点$n的$l，\n招式光明坦荡，正是一式「阳春白雪」",
	"force" : 160,
	"dodge" : 20,
	"damage": 40,
	"lvl" : 40,
	"skill_name" : "阳春白雪",
	"damage_type" : "内伤"
]),
([	"action" : "$N身影飘起，一式「阳钩挥天」，自上而下，左脚弯曲如钩，\n踹向$n的右肩，$n侧身相避，$N右手趁势点向$n的$l",
	"force" : 190,
	"dodge" : 30,
	"damage": 50,
	"lvl" : 60,
	"skill_name" : "阳钩挥天",
	"damage_type" : "内伤"
]),
([	"action" : "只见$N脸上忽地一红，左手一收，一式「烈日骄阳」，右手食指斜指，向$n的$l点去",
	"force" : 220,
	"dodge" : 30,
	"damage": 70,
	"lvl" : 70,
	"skill_name" : "烈日骄阳",
	"damage_type" : "内伤"
]),
([	"action" : "$N左掌斜削，突然间变掌为指，嗤的一声响，一式「丹凤朝阳」，使出一阳指力，疾点$n的$l",
	"force" : 250,
	"dodge" : 20,
	"damage": 80,
	"lvl" : 90,
	"skill_name" : "丹凤朝阳",
	"damage_type" : "内伤"
]),
([	"action" : "$N反身一跃，闪身到$n背后，左膝一屈，右手食指回身一式「阴阳交错」，射向$n的后脑",
	"force" : 280,						  
	"dodge" : 25,
	"damage": 100,
	"lvl" : 100,
	"skill_name" : "阴阳交错",
	"damage_type" : "内伤"
]),
([	"action" : "$N一声大吼, 一式「三阳开泰」，用尽全力向$n的$l点去",
	"force" : 300,
	"dodge" : 10,
	"damage": 120,
	"lvl" : 130,
	"skill_name" : "三阳开泰",
	"damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="haotian-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一阳指必须空手。\n");
	if (me->query("gender") != "男性")
		return notify_fail("你阳气不足，无法学一阳指。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，无法练一阳指。\n");
		
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
	level   = (int) me->query_skill("sun-finger", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练一阳指!\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"sun-finger/" + action;
}
