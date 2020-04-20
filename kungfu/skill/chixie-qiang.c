//chixie-qiang.c
//赤蝎枪法

inherit SKILL;

mapping *action = ({
([      
	"action":"$N使一招「蝎点头」，手中$w一抖，化出无数枪头，直刺$n的$l",
	"dodge":620,
	"parry":500,
	"force" :100,
	"skill_name":"蝎点头",
	"damage_type":  "刺伤",
	"lvl": 0,
]),
([      
	"action":"$N使出赤蝎枪中的「蝎天钩」，手中$w晃动，虚点数枪，突然自影中发出一枪，刺向$n的$l",
	"dodge":620,
	"parry":600,
	"force":200,
	"skill_name":"蝎天钩",
	"damage_type":"割伤",
	"lvl": 20,
]),
([      
	"action":"$N一招「蝎獒松」，向前猛窜，手中$w反背一枪，直扎$n的$l",
	"dodge":630,
	"parry":400,
	"force":50,
	"skill_name":"蝎獒松",
	"damage_type":  "割伤",
	"lvl": 40,
]),
([      "action":"$N手中$w一式「蝎月扣」，手中$w枪头乱抖，铺天盖地杀来，枪枪不离$n的$l",
	"force":90,
	"dodge":230,
	"parry":400,
	"skill_name":"蝎月扣",
	"damage_type":  "刺伤",
	"lvl": 60,
]),
([      
	"action":"$N的$w虚点，蓦地进步跟身，一招「蝎针刺」刺向$n的$l",
	"dodge":200,
	"parry":300,
	"force":300,
	"skill_name":"蝎针刺",
	"damage_type":  "刺伤",
	"lvl": 100,
]),
([      
	"action":"$N手中$w一递，枪身竟如残月般弯转，一招「扑风蝎」反手对准$n$l一枪刺去",
	"dodge":260,
	"parry":330,
	"force":100,
	"skill_name":"扑风蝎",
	"damage_type":  "刺伤",
	"lvl": 120,
]),
});

int valid_learn(object me)
{
	object ob;
	
	if((int)me->query("max_neili") < 100 )
		return notify_fail("你的内力不够，没有办法练赤蝎枪法。\n");
	
	if(!(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "spear" )
		return notify_fail("你必须先找一把枪才能练枪法。\n");

	return 1;
}
int valid_enable(string usage){	return usage=="spear" || usage=="parry";}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("chixie-qiang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习赤蝎枪法。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -3);
	return 1;
}
/*
string perform_action_file(string action)
{
	return CLASS_D("wudujiao") + "/spear/" + action;
}
*/
string *parry_msg = ({
	"$n使出一招「来日方长」，手中的$v荡开了$N的$w。\n",
	"$n使出「视而不见」，将$N的$w封于丈外。\n",
	"$n使出一招「运筹帷幄」，手中的$v化做漫天残照，荡开了$N的$w。\n",
	"$n手中的$v一抖，一招「久历歧途」，向$N拿$w的手腕刺去。\n",
});
string *unarmed_parry_msg = ({
	"$n将手中的$v舞得密不透风，一招「荆榛丛中」封住了$N的攻势。\n",
	"$n反手一招「云浮华相」，整个人消失在一团剑光之中。\n",
	"$n使出一招「胆大妄为」，$v直刺$N的双手。\n",
	"$n将手中的$v一抖，一招「开天辟地」，迫得$N连连后退。\n",
});
string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
