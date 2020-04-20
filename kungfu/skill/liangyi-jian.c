//liangyi-jian.c 两仪剑法

inherit SKILL;

mapping *action = ({
([	"skill_name":   "法分玄素",
	"action" : "$N剑尖剑芒暴长，一招「法分玄素」，手中$w自左下大开大阖，一剑斜上刺向$n的$l",
	"dodge" : 20,
	"damage" : 180,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"skill_name":   "道尽阴阳",
	"action" : "$N剑势圈转，手中$w如粘带连，平平展展挥出，一招「道尽阴阳」轻轻划过$n的$l",
	"dodge" : 20,
	"damage" : 160,
	"lvl" : 10,
	"damage_type" : "刺伤"
]),
([	"skill_name":   "渊临深浅",
	"action" : "$N长剑轻灵跳动，剑随身长，右手$w使出一式「渊临深浅」刺向$n的$l",
	"dodge" : 15,
	"damage" : 150,
	"lvl" : 20,
	"damage_type" : "刺伤"
]),
([	"skill_name":   "水泛青黄",
	"action" : "$N长剑下指，剑意流转，一招「水泛青黄」直取$n的$l",
	"dodge" : 15,
	"damage" : 200,
	"lvl" : 30,
	"damage_type" : "刺伤"
]),
([	"skill_name":   "云含吞吐",
	"action" : "$N剑芒吞吐，幻若灵蛇，右手$w使出一式「云含吞吐」，剑势极尽曼妙，刺向$n的$l",
	"dodge" : 25,
	"damage" : 180,
	"lvl" : 40,
	"damage_type" : "刺伤"
]),
([	"skill_name":   "梦醒蝶庄",
	"action" : "$N屈腕云剑，剑光如彩碟纷飞，幻出点点星光，右手$w使出一式「梦醒蝶庄」跃跃洒洒飘向$n的$l",
	"dodge" : 25,
	"damage" : 220,
	"lvl" : 50,
	"damage_type" : "刺伤"
]),
([	"skill_name":   "人在遐迩",
	"action" : "$N挥剑分击，剑势自胸前跃出，右手$w一式「人在遐迩」，毫无留恋之势，刺向$n的$l",
	"dodge" : 15,
	"lvl" : 60,
	"damage" : 200,
	"damage_type" : "刺伤"
]),
([	"skill_name":   "情系短长",
	"action" : "$N退步，左手剑指划转，腰部一扭，右手$w一记「情系短长」自下而上刺向$n的$l",
	"dodge" : 35,
	"damage" : 250,
	"lvl" : 80,
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage){return (usage== "sword") || (usage== "parry");}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 50)
		return notify_fail("你的太极神功火候太浅。\n");
	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("liangyi-jian", 1) )
		return notify_fail("你的基本剑法火候太浅。\n");
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
	level   = (int) me->query_skill("liangyi-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			   return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练两仪剑法。\n");
	me->receive_damage("qi", 10);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"liangyi-jian/" + action;
}

