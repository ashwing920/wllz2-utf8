// songshan-sword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"skill_name":	"万岳朝宗",
	"action":	"$N右手$w一立，举剑过顶，弯腰躬身，使一招‘万岳朝宗’正是嫡系正宗的嵩山剑法",
	"dodge":	50,
	"damage":	170,
	"lvl":		10,
	"damage_type":  "刺伤"
]),
([	"skill_name":	"千古人龙",
	"action":	"$N手中$w突然间剑光一吐，化作一道白虹，端严雄伟，端丽飘逸，\n正是嵩山剑法的精要所在，一招‘千古人龙’向$n$l直刺过来",
	"dodge":	-70,
	"damage":	120,
	"lvl":		20,
	"damage_type":  "刺伤"
]),
([	"skill_name":	"叠翠浮青",
	"action":	"$N手中$w突然间剑光一吐，一招‘叠翠浮青’化成一道青光，气壮雄浑，向$n$l直刺过来",
	"dodge":	-70,
	"damage":	120,
	"lvl":		40,
	"damage_type":  "刺伤"
]),
([	"skill_name":	"玉进天池",
	"action":	"$N手中$w剑光一吐，一招‘玉进天池’威仪整肃，端严雄伟，向$n$l直刺过来",
	"dodge":	-70,
	"damage":	120,
	"lvl":		60,
	"damage_type":  "刺伤"
]),
([	"skill_name":	"开门见山",
	"action":	"$N左手向外一分，右手$w向右掠出，使的是嵩山派剑法‘开门见山’",
	"dodge":	-70,
	"damage":	120,
	"lvl":		80,
	"damage_type":  "刺伤"
]),
([	"skill_name":	"独劈华山",
	"action":	"$N手中$w自上而下的向$n直劈下去，一招‘独劈华山’，\n真有石破天惊的气势，将嵩山剑法之所长发挥得淋漓尽致",
	"dodge":	-40,
	"damage":	90,
	"lvl":		100,
	"damage_type":  "刺伤"
]),
([	"skill_name":	"天外玉龙",
	"action":	"$N手中$w刷的一剑自左而右急削过去，正是一招嵩山派正宗剑法‘天外玉龙’。\n但见$w自半空中横过，剑身似曲似直，长剑便如一件活物一般",
	"dodge":	-40,
	"damage":	140,
	"lvl":		120,
	"damage_type":  "刺伤"
]),
});

int valid_learn(object me)
{
	object ob;
	if( (int)me->query("neili") < 50 )
		return notify_fail("你的内力不够，没有办法练嵩山剑法。\n");
	if( !(ob = me->query_temp("weapon"))
	||	  (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	||	  (int)me->query("neili") < 5 )
	return notify_fail("你的内力或气不够，没有办法练习嵩山剑法。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -5);
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return __DIR__"songshan-sword/" + action;
}
