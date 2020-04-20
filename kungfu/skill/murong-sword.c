// murong-sword.c - 慕蓉剑法

inherit SKILL;

mapping *action = ({
([	"action" : "$N向前踏上一步，一招「恒山剑法」，$w剑势如风，刺向$n的$l要害",
	"force"  	: 80,
        "dodge"  	: 5,
        "parry"  	: 5,
	"damage" 	: 5,
	"lvl"    	: 0,
	"skill_name"  	: "恒山剑法",
	"damage_type" 	: "刺伤"
]),
([	"action" : "$N双足轻点，一招「衡山剑法」，手中$w狂风骤雨般地向$n的$l刺去",
	"force"  	: 100,
        "dodge"  	: 5,
        "parry"  	: 5,
	"damage" 	: 10,
	"lvl"    	: 10,
	"skill_name"  	: "衡山剑法",
	"damage_type" 	: "刺伤"
]),
([	"action" : "只见$N手中$w轻轻颤动，一招「泰山剑法」，斜斜地划向$n的$l要害",
	"force"  	: 120,
        "dodge"  	: 10,
        "parry"  	: 10,
	"damage" 	: 20,
	"lvl"    	: 20,
	"skill_name"  	: "泰山剑法",
	"damage_type" 	: "割伤"
]),
([	"action" : "$N横剑上前，身形一转，一招「嵩山剑法」，$w挟呼呼风声迅猛刺向$n的$l",
	"force"  	: 140,
        "dodge"  	: 20,
        "parry"  	: 20,
	"damage" 	: 30,
	"lvl"    	: 30,
	"skill_name"  	: "嵩山剑法",
	"damage_type" 	: "刺伤"
]),
([	"action" : "$N纵身一跃，手中$w一招「华山剑法」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
	"force"  	: 160,
        "dodge"  	: 30,
        "parry"  	: 30,
	"damage" 	: 40,
	"lvl"    	: 40,
	"skill_name"  	: "华山剑法",
	"damage_type" 	: "刺伤"
]),
([	"action" : "$N一招「昆仑剑法」，剑锋平指，剑势如风，手中$w直刺$n的$l",
	"force"  	: 180,
        "dodge"  	: 40,
        "parry"  	: 40,
	"damage" 	: 50,
	"lvl"    	: 50,
	"skill_name"  	: "昆仑剑法",
	"damage_type" 	: "刺伤"
]),
([	"action" : "$N身形一转，一招「峨眉剑法」，$w剑光不定，招招刺向$n的$l要害",
	"force"  	: 200,
        "dodge"  	: 50,
        "parry"  	: 50,
	"damage" 	: 60,
	"lvl"    	: 60,
	"skill_name"  	: "峨眉剑法",
	"damage_type" 	: "割伤"
]),
([	"action" : "$N一招「逍遥剑法」，$n只觉得眼前一花，全身被笼罩在一团剑气之中",
	"force"  	: 220,
        "dodge"  	: 60,
        "parry"  	: 60,
	"damage" 	: 80,
	"lvl"    	: 70,
	"skill_name"  	: "逍遥剑法",
	"damage_type" 	: "刺伤"
]),
([	"action" : "$N错步上前，一招「少林剑法」，剑意若有若无，$w淡淡地向$n的$l挥去",
	"force"  	: 240,
        "dodge"  	: 70,
        "parry"  	: 70,
	"damage" 	: 100,
	"lvl"    	: 80,
	"skill_name"  	: "怜我世人",
	"damage_type" 	: "割伤"
]),
([	"action" : "$N一招「武当剑法」，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
	"force"  	: 260,
        "dodge"  	: 80,
        "parry"  	: 80,
	"damage" 	: 120,
	"lvl"    	: 100,
	"skill_name"  	: "忧患实多",
	"damage_type" 	: "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        object ob;
	if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力不够。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练慕蓉剑法。\n");
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
	level   = (int) me->query_skill("murong-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"]) return action[random(i)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力不够练慕容剑法。\n");
	me->receive_damage("qi", 35);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"murong-sword/" + action;
}
