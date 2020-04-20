// yitian-sword.c - 倚天剑法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "但见$N手中$w剑光不定，一招「拔云见日」对着$n的$l一连刺出三剑",
	"force"         : 120,
	"dodge"         : 10,
	"parry"         : 10,
	"damage"        : 20,
	"lvl"           : 0,
	"skill_name"    : "拔云见日",
	"damage_type"   : "刺伤"
]),
([      "action" : "$N向前踏出一步，一招「怀中抱月」，左手虚抱，右手$w斜斜地划向$n的$l要害",
	"force"         : 140,
	"dodge"         : 20,
	"parry"         : 20,
	"damage"        : 20,
	"lvl"           : 10,
	"skill_name"    : "怀中抱月",
	"damage_type"   : "割伤"
]),
([      "action" : "只见$N手中$w轻轻颤动，一招「星落长空」连刺$n几处要害",
	"force"         : 160,
	"dodge"         : 30,
	"parry"         : 30,
	"damage"        : 30,
	"lvl"           : 20,
	"skill_name"    : "星落长空",
	"damage_type"   : "刺伤"
]),
([      "action" : "$N横剑上前，一招「排云推月」，剑锋直出，绵绵不断，$w连刺$n几处要害",
	"force"         : 180,
	"dodge"         : 40,
	"parry"         : 40,
	"damage"        : 40,
	"lvl"           : 30,
	"skill_name"    : "排云推月",
	"damage_type"   : "刺伤"
]),
([      "action" : "$N纵身一跃，一招「星河在天」，$n只觉得全身被笼罩在一团剑气之中。",
	"force"         : 200,
	"dodge"         : 50,
	"parry"         : 50,
	"damage"        : 60,
	"lvl"           : 40,
	"skill_name"    : "星河在天",
	"damage_type"   : "刺伤"
]),
([      "action" : "$N身形一转，一招「斗摇星汉」，$w剑势如风，刺向$n的$l要害",
	"force"         : 280,
	"dodge"         : 40,
	"parry"         : 80,
	"damage"        : 100,
	"lvl"           : 60,
	"skill_name"    : "斗摇星汉",
	"damage_type"   : "刺伤"
]),
([      "action" : "只见$N一招「起凤腾蛟」，手中$w剑光不定，如风一般卷向$n的$l",
	"force"         : 220,
	"dodge"         : 60,
	"parry"         : 60,
	"damage"        : 80,
	"lvl"           : 50,
	"skill_name"    : "起凤腾蛟",
	"damage_type"   : "割伤"
]),
([      "action" : "$N错步上前，一招「青龙取水」，中宫直进，手中$w猛地刺向$n的$l",
	"force"         : 240,
	"dodge"         : 70,
	"parry"         : 70,
	"damage"        : 100,
	"lvl"           : 60,
	"skill_name"    : "青龙取水",
	"damage_type"   : "刺伤"
]),
([      "action" : "$N将身一幌，一招「倚天不出」，剑意若有若无，$w淡淡地向$n的$l挥去",
	"force"         : 260,
	"dodge"         : 80,
	"parry"         : 80,
	"damage"        : 140,
	"lvl"           : 100,
	"skill_name"    : "倚天不出",
	"damage_type"   : "割伤"
]),
([      "action" : "$N潜运真力，一招「谁与争锋」，手中$w运发剑气，闪电般破空射向$n的$l",
	"force"         : 280,
	"dodge"         : 90,
	"parry"         : 90,
	"damage"        : 180,
	"lvl"           : 150,
	"skill_name"    : "谁与争锋",
	"damage_type"   : "刺伤"
]),
});
int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	object ob;
	int level;

	if( me->query("gender") != "女性")
		return notify_fail("只有女性才可以学这种武功。\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力不够。\n");
	if( !(ob = me->query_temp("weapon"))
	||      (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练倚天剑法。\n");
	level= me->query_skill("yitian-sword");
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
	int i, j, level;

	level =(int)me->query_skill("yitian-sword",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
		if (level >= 400 && random(6) > 3 ) {
			return ([
				"action": HIW + action[j]["action"] + NOR,
				"force" : action[j]["force"],
				"parry" : action[j]["parry"],
				"dodge" : action[j]["dodge"],
				"damage": level / 6,
				"lvl":    action[j]["lvl"],
				"damage_type" : random(2)?"刺伤":"鞭伤",
		    ]);
	       }
	    return action[j];
	}
    }
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力不够练倚天剑法。\n");
	me->receive_damage("qi", 35);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yitian-sword/" + action;
}
