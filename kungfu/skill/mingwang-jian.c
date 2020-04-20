// mingwang-jian.c 冥王剑

inherit SKILL;

mapping *action = ({
([      "action":"$N怒目圆睁，使出一招「冥王」，手中$w一抖，直刺$n的$l",
	"skill_name":"不动冥王",
	"force" : 100,
	"dodge" : -10,
	"lvl" : 0,
	"damage" : 30,
	"damage_type" : "刺伤",
]),
([      "action":"$N使出一式「起手出剑」，足下一滑，剑芒闪向$n的$l",
	"skill_name":"起手出剑",
	"force" : 140,
	"dodge" : 5,
	"lvl" : 8,
	"damage" : 60,
	"damage_type" : "刺伤",
]),
([      "action":"$N使出一招「山崩」，纵身跃入半空，$w如山崩般劈向$n的$l",
	"skill_name":"山崩",
	"force" : 180,
	"dodge" : -10,
	"lvl" : 16,
	"damage" : 80,
	"damage_type" : "割伤",
]),
([      "action":"$N使出「千旋转」，将$w舞得如纺车一般，忽然一剑刺向$n的$l",
	"skill_name":"千旋转",
	"force" : 220,
	"dodge" : 10,
	"lvl" : 24,
	"damage" : 100,
	"damage_type" : "刺伤",
]),
([      "action":"$N使出一招「降魔舞」，全身劲气贯于$w中，剑气直指$n的$l",
	"skill_name":"降魔舞",
	"force" : 250,
	"dodge" : 10,
	"lvl" : 32,
	"damage" : 154,
	"damage_type" : "刺伤",
]),
([      "action":"$N单足独立，使出一式「鹤舞」，一道剑光如白影般向$n的$l扫去",
	"skill_name":"鹤舞",
	"force" : 280,
	"dodge" : 15,
	"lvl" : 40,
	"damage" : 180,
	"damage_type" : "割伤",
]),
([      "action":"$N使出一招「龙腾」，手中$w如游龙般扑向$n的$l",
	"skill_name":"龙腾",
	"force" : 300,
	"dodge" : 20,
	"lvl" : 48,
	"damage" : 200,
	"damage_type" : "割伤",
]),
([      "action":"$N飞身一跃，居高临下使出「花雨满天」，顿时剑尖如雨刺向$n的$l",
	"skill_name":"花雨漫天",
	"force" : 320,
	"dodge" : 25,
	"lvl" : 80,
	"damage" : 250,
	"damage_type" : "刺伤",
]),
([      "action" : "$N使出一式「大悲」，$N手中的$w已经迅捷无比的刺向$n的$l。  ",
	"skill_name" : "大悲",
	"force" : 350,
	"dodge" : 30,
	"lvl" : 100,
	"damage" : 320,
	"damage_type" : "刺伤",
]),
([      "action" : "$N使出一式「出剑」，简单而有效地往$n的$l刺去。",
	"skill_name" : "出剑",
	"force" : 360,
	"dodge" : 35,
	"lvl" : 150,
	"damage" : 350,
	"damage_type" : "刺伤",
]),
([      "action" : "$N使出一招「不动」，身形一转，反手一挥，手中$w刺向$n的$l。",
	"skill_name" : "不动",
	"force" : 380,
	"dodge" : 40,
	"lvl" : 200,
	"damage" : 380,
	"damage_type" : "割伤",
]),
([      "action" : "$N使出「初醒」，双脚点地，全身转出一团剑光滚向$n。",
	"skill_name" : "初醒",
	"force" : 400,
	"dodge" : 50,
	"lvl" : 250,
	"damage" : 400,
	"damage_type" : "刺伤",
]),
([      "action" : "$N使出一招「无涯」，全身劲气贯于$w中，一片剑光袭向$n的$l。",
	"skill_name" : "无涯",
	"force" : 420,
	"dodge" : 50,
	"lvl" : 300,
	"damage" : 440,
	"damage_type" : "刺伤",
]),
([      "action" : "$N剑锋忽转，一式「冲霄」，闪电般刺向$n的$l。",
	"skill_name" : "冲霄",
	"force" : 440,
	"dodge" : 60,
	"lvl" : 320,
	"damage" : 480,
	"damage_type" : "割伤",
]),
([      "action" : "$N使出一招「归宗」，手中$w狂风骤雨般地向$n的$l连攻数剑。",
	"skill_name" : "归宗",
	"force" : 460,
	"dodge" : 80,
	"lvl" : 350,
	"damage" : 530,
	"damage_type" : "割伤",
]),
([      "action" : "$N舞动$w发出逼人剑气刺去，一招「狂雷」，挟著闪闪剑光刺向$n的$l。",
	"skill_name" : "狂雷",
	"force" : 480,
	"dodge" : 90,
	"lvl" : 400,
	"damage" : 550,
	"damage_type" : "刺伤",
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("force", 1) <= 30 )
		return notify_fail("你的基本内功火候不够。\n");
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
	level   = (int) me->query_skill("mingwang-jian",1);
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
		return notify_fail("你的体力不够，练不了冥王剑。\n");
	me->receive_damage("qi", 20);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"mingwang-jian/" + action;
}
