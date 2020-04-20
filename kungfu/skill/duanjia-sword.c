// duanjia-sword.c 段家剑
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit SKILL;

mapping *action = ({
([	"action" : "$N向前跨上一步，一招「云横秦岭」，手中$w自左向右向$n的$l缓缓划去",
	"force" : 100,
	"dodge" : 20,
	"damage" : 25,
	"lvl" : 0,
	"skill_name" : "云横秦岭",
	"damage_type" : "刺伤"
]),
([	"action" : "$N向上跃起，左手剑诀，右手一抖，$w剑光缦妙如瀑，一式「飞流直下」直刺$n的$l",
	"force" : 120,
	"dodge" : 15,
	"damage" : 30,
	"lvl" : 9,
	"skill_name" : "飞流直下",
	"damage_type" : "刺伤"
]),
([  	"action" : "$N一招「雪涌兰关」，$w闪起数道寒光，自下而上反挑$n的$l",
	"force" : 140,
	"dodge" : 15,
	"damage" : 35,
	"lvl" : 19,
	"skill_name" : "雪涌兰关",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「奇兵突起」，手中$w看似横扫实则斜劈，刺向$n的$l",
	"force" : 160,
	"dodge" : 10,
	"damage" : 45,
	"lvl" : 29,
	"skill_name" : "奇兵突起",
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出「夜叉探海」，$w挽出三个剑花，绵绵不断划向$n的$l",
	"force" : 180,
	"dodge" : 10,
	"damage" : 60,
	"lvl" : 39,
	"skill_name" : "夜叉探海",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「泰山压顶」，左手一捏剑诀，右手$w自上而下雷霆万钧般直向$n的$l劈乐下去",
	"force" : 210,
	"dodge" : 5,
	"damage" : 70,
	"lvl" : 49,
	"skill_name" : "泰山压顶",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「雨打梨花」，身在半空，$w回抽，反手勾向$n的$l",
	"force" : 250,
	"dodge" : 10,
	"damage" : 90,
	"lvl" : 69,
	"skill_name" : "雨打梨花",
	"damage_type" : "刺伤"
]),
([	"action" : "$N身影一晃, 绕到$n背后，一招「逐鹿中原」，剑尖向$n的$l疾挑",
	"force" : 300,
	"dodge" : -5,
	"damage" : 100,
	"lvl" : 89,
	"skill_name" : "逐鹿中原",
	"damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
	   return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("kurong-changong", 1) < 20)
	   return notify_fail("你的枯荣禅功火候太浅。\n");
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
	level   = (int) me->query_skill("duanjia-sword",1);
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
		return notify_fail("你的体力不够练段家剑。\n");
	me->receive_damage("qi", 20);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"duanjia-sword/" + action;
}
