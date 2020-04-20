// yunu-sword.c 玉女金针十三剑

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([ "skill_name":"穿针引线",
	   "action":  "$N使一招「穿针引线」，脚踏中宫，手中$w直指$n$l",
	   "dodge":   50,
	   "damage":  170,
	   "lvl": 30,
	   "damage_type":  "刺伤"
	]),
	([ "skill_name":"天衣无缝",
	   "action":  "$N剑随身转，一招「天衣无缝」，撒出一片剑影，罩向$n的$l",
	   "dodge":   30,
	   "damage":  80,
	   "lvl": 10,
	   "damage_type":  "刺伤"
	]),
	([ "skill_name":	"夜绣鸳鸯",
	   "action":  "$N舞动$w，使出一招「夜绣鸳鸯」剑光忽左忽右，闪烁不定，直刺$n的$l",
	   "dodge":   40,
	   "damage":  90,
	   "lvl":     40,
	   "damage_type":  "刺伤"
	]),
	([ "skill_name":	"织女穿梭",
	   "action":  "$N一声娇喝，祭出「织女穿梭」，手中$w化为一道弧光，射向$n的$l",
	   "dodge":   40,
	   "damage":  60,
	   "lvl":     20,
	   "damage_type":  "刺伤"
	]),
	([ "skill_name":	"小鸟依人",
	   "action":  "$N忽然蹂身直上，一招「小鸟依人」，手中$w自下往上刺向$n的$l",
	   "dodge":   50,
	   "damage":  90,
	   "lvl":     50,
	   "damage_type":  "刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;
	if( (string)me->query("gender") != "女性" )
		return notify_fail("玉女金针十三剑是只有女子才能练的武功。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力不够，没有办法练玉女金针十三剑。\n") ;
	if( (string)me->query_skill_mapped("force")!= "zixia-shengong")
		return notify_fail("玉女金针十三剑必须配合紫霞神功才能练。\n");
	if( !(ob = me->query_temp("weapon"))
		|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
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
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	||  (int)me->query("neili") < 5 )
	  return notify_fail("你的内力或气不够，没有办法练习玉女金针十三剑。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -5);
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return __DIR__"yunu-sword/" + action;
}
