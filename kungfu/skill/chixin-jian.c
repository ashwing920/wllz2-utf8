// chixin-jian.c 痴心情长剑
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action":"$N使一式「"HIR"一见如故"NOR"」，手中$w拦腰横扫向向$n的$l",
	"force" : 120,
	"dodge" : 0,
	"damage": 30,
	"lvl" : 0,
	"skill_name" : "一见如故",
	"damage_type":  "割伤"
]),
([	"action":"$N踏上一步，状似「"HIC"心弛神往"NOR"」，手中$w飞出一道剑光刺向$n的$l",
	"force" : 140,
	"dodge" : 10,
	"damage": 50,
	"lvl" : 9,
	"skill_name" : "心驰神往",
	"damage_type":  "割伤"
]),
([	"action":"$N手中$w一抖，一招「"HIM"柔情似水"NOR"」，缓缓一剑刺出，攻向$n的$l",
	"force" : 160,
	"dodge" : 5,
	"damage": 60,
	"lvl" : 18,
	"skill_name" : "柔情似水",
	"damage_type":  "刺伤"
]),
([	"action":"$N手中$w连绕数个大圈，一式「"HIG"佳期如梦"NOR"」，剑光化作长虹飞向$n的$l",
	"force" : 180,
	"dodge" : 10,
	"damage": 70,
	"lvl" : 27,
	"skill_name" : "佳期如梦",
	"damage_type":  "刺伤"
]),
([	"action":"$N一式「"HIG"巧笑倩兮"NOR"」，左手托腮，右手作兰花指握剑$w挥向$n的$l",
	"force" : 220,
	"dodge" : 15,
	"damage": 90,
	"lvl" : 36,
	"skill_name" : "巧笑倩兮",
	"damage_type":  "割伤"
]),
([	"action":"$N手中$w斜指苍天，一式「"HIC"魂牵梦绕"NOR"」，剑光如蛛网对准$n的$l击出",
	"force" : 260,
	"dodge" : 5,
	"damage": 100,
	"lvl" : 44,
	"skill_name" : "魂牵梦绕",
	"damage_type":  "刺伤"
]),
([	"action":"$N一式「"HIB"死去活来"NOR"」，手腕急抖，挥洒出万点金光，刺向$n的$l",
	"force" : 320,
	"dodge" : 5,
	"damage": 105,
	"lvl" : 52,
	"skill_name" : "死去活来",
	"damage_type":  "刺伤"
]),
([	"action":"$N一式「"HIR"相亲相爱"NOR"」，$w飞斩盘旋，如情人的手伸向$n的胸口",
	"force" : 380,
	"dodge" : 5,
	"damage": 110,
	"lvl" : 60,
	"skill_name" : "相亲相爱",
	"damage_type":  "刺伤"
]),
([	"action":"$N使一式「"HIM"生死相许"NOR"」，手中$w合身疾刺$n的胸口，势不可当",
	"force" : 380,
	"dodge" : 5,
	"damage": 120,
	"lvl" : 70,
	"skill_name" : "生死相许",
	"damage_type":  "刺伤"
]),
([	"action":"$N手中$w划出一道艳丽的弧线，直奔$n的$l，却是一招「"HIW"美人如花"NOR"」",
	"force" : 380,
	"dodge" : 5,
	"damage": 130,
	"lvl" : 80,
	"skill_name" : "美人如花",
	"damage_type":  "刺伤"
]),
([	"action":"$N回剑自守，使一式「"HIY"天长地远"NOR"」，蓦地手中$w向$n击出",
	"force" : 380,
	"dodge" : 5,
	"damage": 145,
	"lvl" : 90,
	"skill_name" : "天长地远",
	"damage_type":  "刺伤"
]),
([	"action":"$N左足踢起，一式「"HIW"白头到老"NOR"」，$w从不可思议的角度刺向$n",
	"force" : 380,
	"dodge" : 5,
	"damage": 150,
	"lvl" : 114,
	"skill_name" : "白头到老",
	"damage_type":  "刺伤"
]),
([	"action":"$N一式「"HIW"天长地久"NOR"」，$w突然一飞冲天，一片金光围掠$n全身,然后凌空而下",
	"force" : 380,
	"dodge" : 5,
	"damage": 160,
	"lvl" : 129,
	"skill_name" : "天长地久",
	"damage_type":  "刺伤"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query_skill("force", 1) < 15 &&
		(int)me->query_skill("beiming-shengong", 1) < 15)
		return notify_fail("你的内功心法火候不到，无法学习痴心情长剑。\n");
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
	level   = (int) me->query_skill("chixin-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练痴心情长剑。\n");
	me->receive_damage("qi", 25);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"chixin-jian/" + action;
}
