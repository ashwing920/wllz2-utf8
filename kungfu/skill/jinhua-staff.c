// jinhua-staff.c - 金花杖法

inherit SKILL;

mapping *action = ({
([	"action" : "只见$N手中$w伸出，一招「百花齐放」，指天打地，挑向$n的$l",
	"force"  	: 50,
	"dodge"  	: -10,
	"parry"  	: -10,
	"damage" 	: 5,
	"lvl"    	: 0,
	"skill_name"  	: "百花齐放",
	"damage_type" 	: "挫伤"
]),
([	"action" : "$N提起$w，一招「沧海横流」，击向$n的$l，出手狠辣，正是「金花杖法」中的招数",
	"force"  	: 80,
	"dodge"  	: -5,
	"parry"  	: -5,
	"damage" 	: 10,
	"lvl"    	: 10,
	"skill_name"  	: "沧海横流",
	"damage_type" 	: "挫伤"
]),
([	"action" : "$N纵身轻轻跃起，一招「春风花雨」，手中$w猛一探，直扫$n的$l",
	"force"  	: 100,
	"dodge"  	: 1,
	"parry"  	: 1,
	"damage" 	: 20,
	"lvl"    	: 20,
	"skill_name"  	: "春风花雨",
	"damage_type" 	: "挫伤"
]),
([	"action" : "只见$N向前踏上一步，手中$w阵阵风响，一招「滴水穿石」向$n的$l攻去",
	"force"  	: 120,
	"dodge"  	: 10,
	"parry"  	: 10,
	"damage" 	: 30,
	"lvl"    	: 30,
	"skill_name"  	: "滴水穿石",
	"damage_type" 	: "挫伤"
]),
([	"action" : "$N将身一幌，手中$w一挥，使出一招「风卷残云」，忽左忽右扫向$n的$l",
	"force"  	: 140,
	"dodge"  	: 20,
	"parry"  	: 20,
	"damage" 	: 40,
	"lvl"    	: 40,
	"skill_name"  	: "风卷残云",
	"damage_type" 	: "挫伤"
]),
([	"action" : "$N潜运真力，举起$w，居高临下使一招「风流云散」砸向$n的$l",
	"force"  	: 160,
	"dodge"  	: 30,
	"parry"  	: 30,
	"damage" 	: 50,
	"lvl"    	: 50,
	"skill_name"  	: "风流云散",
	"damage_type" 	: "挫伤"
]),
([	"action" : "只见$N错步上前，一招「浮光掠影」，手中$w猛烈扫向$n的$l",
	"force"  	: 180,
	"dodge"  	: 40,
	"parry"  	: 40,
	"damage" 	: 60,
	"lvl"    	: 60,
	"skill_name"  	: "浮光掠影",
	"damage_type" 	: "挫伤"
]),
([	"action" : "$N拔步挺腰，使出一招「大江东去」，高举手中$w，劈头砸向$n的$l",
	"force"  	: 200,
	"dodge"  	: 50,
	"parry"  	: 50,
	"damage" 	: 70,
	"lvl"    	: 70,
	"skill_name"  	: "大江东去",
	"damage_type" 	: "挫伤"
]),
([	"action" : "$N手中$w从旁递出，一招「长袖善舞」，$w侧抖旁缠，向外斜甩，攻向$n",
	"force"  	: 220,
	"dodge"  	: 60,
	"parry"  	: 60,
	"damage" 	: 80,
	"lvl"    	: 80,
	"skill_name"  	: "长袖善舞",
	"damage_type" 	: "挫伤"
]),
([	"action" : "$N腾空而起，手中$w一抖，使出一招「穿云裂石」，如山杖影，疾疾压向$n",
	"force"  	: 240,
	"dodge"  	: 70,
	"parry"  	: 70,
	"damage" 	: 100,
	"lvl"    	: 100,
	"skill_name"  	: "穿云裂石",
	"damage_type" 	: "挫伤"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	object ob;

	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if( !(ob = me->query_temp("weapon"))
	||      (string)ob->query("skill_type") != "staff" )
		return notify_fail("你必须先找一根杖才能练金花杖法。\n");
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
	int i, level;
	level   = (int) me->query_skill("jinhua-staff",1);
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"]) return action[random(i)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力不够练金花杖法。\n");
	me->receive_damage("qi", 35);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jinhua-staff/" + action;
}
