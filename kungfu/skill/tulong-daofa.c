// tulong-blade.c - 屠龙刀法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "只见$N向前踏上一步，一招「拔云见日」，杀气腾腾，手中的$w横扫$n的$l",
	"force"         : 140,
	"dodge"         : 15,
	"parry"         : 30,
	"damage"        : 30,
	"lvl"           : 0,
	"skill_name"    : "拔云见日",
	"damage_type"   : "割伤"
]),
([      "action" : "$N将身一幌，一招「苍龙出水」，$w划出几个圆圈，招招不离$n的$l要害",
	"force"         : 170,
	"dodge"         : 20,
	"parry"         : 40,
	"damage"        : 60,
	"lvl"           : 30,
	"skill_name"    : "苍龙出水",
	"damage_type"   : "割伤"
]),
([      "action" : "只见$N手中$w刀光不定，一招「星落长空」，挟呼呼风声迅猛砍向$n的$l",
	"force"         : 200,
	"dodge"         : 25,
	"parry"         : 50,
	"damage"        : 80,
	"lvl"           : 50,
	"skill_name"    : "星落长空",
	"damage_type"   : "割伤"
]),
([      "action" : "但见$N一招「雨急风狂」，$w从上至下猛劈，挟爆裂之声骤然斩向$n的$l",
	"force"         : 210,
	"dodge"         : 30,
	"parry"         : 60,
	"damage"        : 120,
	"lvl"           : 80,
	"skill_name"    : "雨急风狂",
	"damage_type"   : "割伤"
]),
([      "action" : "$N虚步提腰，，一招「气冲霄汉」，$w划出一个大弧，平平地向$n的$l挥去",
	"force"         : 260,
	"dodge"         : 35,
	"parry"         : 70,
	"damage"        : 150,
	"lvl"           : 100,
	"skill_name"    : "气冲霄汉",
	"damage_type"   : "割伤"
]),
([      "action" : "只见$N错步向前，一招「流星赶月」，刀势如风，手中$w斩向$n的$l",
	"force"         : 280,
	"dodge"         : 40,
	"parry"         : 80,
	"damage"        : 200,
	"lvl"           : 140,
	"skill_name"    : "流星赶月",
	"damage_type"   : "割伤"
]),
([      "action" : "$N向前踏上一步，手中$w一挥，一招「武林至尊」，拦腰砍向$n",
	"force"         : 300,
	"dodge"         : 45,
	"parry"         : 90,
	"damage"        : 240,
	"lvl"           : 180,
	"skill_name"    : "武林至尊",
	"damage_type"   : "割伤"
]),
([      "action" : "只见$N向上纵起，一式「宝刀屠龙」，$w发出耀眼光芒，刀光不定，绵绵不断",
	"force"         : 350,
	"dodge"         : 60,
	"parry"         : 110,
	"damage"        : 280,
	"lvl"           : 220,
	"skill_name"    : "宝刀屠龙",
	"damage_type"   : "割伤"
]),
([      "action" : "只见$N一招「号令天下」，手中$w化作漫天交缠着的刀影将$n重重围住",
	"force"         : 400,
	"dodge"         : 70,
	"parry"         : 120,
	"damage"        : 400,
	"lvl"           : 260,
	"skill_name"    : "号令天下",
	"damage_type"   : "割伤"
]),
([      "action" : "$N潜运真力，一招「莫敢不从」，只见漫天刀影有如排山倒海般的向$n压去",
	"force"         : 500,
	"dodge"         : 80,
	"parry"         : 140,
	"damage"        : 320,
	"lvl"           : 280,
	"skill_name"    : "莫敢不从",
	"damage_type"   : "割伤"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
	object ob;

	if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力不够。\n");

	if( !(ob = me->query_temp("weapon"))
	||      (string)ob->query("skill_type") != "blade" )
		return notify_fail("你必须先找一把刀才能练屠龙刀法。\n");
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
	level = (int) me->query_skill("tulong-daofa",1);
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"]) return action[random(i)];
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	int skill_level;
	object weapon;
	skill_level= (int)me->query_skill("tulong-daofa",1);
	weapon = me->query_temp("weapon");
	if(weapon && weapon->query("id") == "tulong dao"
	&& me->is_fighting(victim) && victim->is_fighting(me))
	if(random(skill_level) > 200 && (int)me->query("neili") > 2000){
		me->add("neili",-random(500)-300);
		message_vision(WHT"\n只见$N手中的"+ weapon->name() + WHT+"刀光闪闪，一股强烈的刀气随着$N的招式，向$n袭去。\n"NOR,me,victim);
		COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),1);
		return 1;
	}
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	||      (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力不够练屠龙刀法。\n");
	me->receive_damage("qi", 35);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tulong-daofa/" + action;
}
