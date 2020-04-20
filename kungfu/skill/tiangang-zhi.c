// tiangang-zhi.c 天罡指穴法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action" : "$N左手轻轻拨动，右手五指徐徐弹出拨，一式「浪起湖心」，拂向$n的$l",
	"force" : 150,
	"dodge" : 5,
	"damage_type" : "瘀伤",
	"lvl" : 0,
	"skill_name" : "浪起湖心"
]),
([	"action" : "$N双手上下起落，俯身掠向$n，一式「瀑落清潭」，左手化掌成指，汹涌袭向$n的$l",
	"force" : 200,
	"dodge" : 5,
	"damage_type" : "瘀伤",
	"lvl" : 12,
	"skill_name" : "瀑落清潭"
]),
([	"action" : "$N左手由拳变掌，右手扭曲如灵蛇，一式「龟蛇竞渡」，左右并用，拍向$n的$l",
	"force" : 250,
	"dodge" : 15,
	"damage_type" : "内伤",
	"lvl" : 24,
	"skill_name" : "龟蛇竞渡"
]),
([	"action" : "$N一式「倒索攀山」，左手抽回，右手前探，戟指点向$n的$l",	
	"force" : 300,
	"dodge" : -5,
	"damage_type" : "瘀伤",
	"lvl" : 36,
	"skill_name" : "倒索攀山"
]),
([	"action" : "$N使一式「闪现雷鸣」，身影变幻不定地掠至$n身后，猛地拍向$n的$l",
	"force" : 350,
	"dodge" : 10,
	"damage_type" : "瘀伤",
	"lvl" : 48,
	"skill_name" : "闪现雷鸣"
]),
([	"action" : "$N两臂大开大阖，吸一口气，一式「地动山摇」，劲力透彻，\n双手快速一拨，激出数道劲气逼向$n的$l",
	"force" : 400,
	"dodge" : 5,
	"damage_type" : "瘀伤",
	"lvl" : 60,
	"skill_name" : "地动山摇"
]),
([	"action" : "$N身形纵起，衣袂飘荡，双手轻轻拍动，一式「水拍云崖」，\n居高临下，连绵不绝拍向$n的$l",
	"force" : 450,
	"dodge" : 20,
	"damage_type" : "内伤",
	"lvl" : 72,
	"skill_name" : "水拍云崖"
]),
([	"action" : "$N腾空而起，双掌合一，十指如钩，一招「泰山压顶」，疾向$n的击落，势道凶猛已极",
	"force" : 500,
	"dodge" : 25,
	"damage_type" : "内伤",
	"lvl" : 84,
	"skill_name" : "泰山压顶"
])
});

int valid_enable(string usage) { return usage=="finger" ||  usage=="parry"; }   

int valid_combine(string combo) { return combo=="jinding-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail(HIC"练天罡指穴法必须空手。\n"NOR);
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("你的临济十二庄火候不够，无法学天罡指穴法。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练天罡指穴法。\n");
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
	level = (int)me->query_skill("tiangang-zhi", 1);
	for(i = sizeof(action); i > 0; i--)
	if(level > action[i-1]["lvl"])
	return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
   return notify_fail("你的体力太低了，无法练天罡指穴法。\n");
	me->receive_damage("qi", 20);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tiangang-zhi/" + action;
}
