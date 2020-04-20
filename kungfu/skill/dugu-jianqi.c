// dugu-jianqi.c - 独孤剑气

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" :      "$N一式「破剑式」，$w如梭，剑气如风，直刺$n的$l",
	"force"         : 180,
	"dodge"         : 20,
	"damage"        : 50,
	"lvl"           : 0,
	"skill_name"    : "破剑式",
	"damage_type"   : "刺伤"
]),
([      "action" :      "$N一式「破刀式」，手中$w剑气划出一个大弧，平平地向$n的$l挥去",
	"force"         : 200,
	"dodge"         : 30,
	"damage"        : 150,
	"lvl"           : 50,
	"skill_name"    : "破刀式",
	"damage_type"   : "砍伤"
]),
([      "action" :      "$N向前跃上一步，使出一式「破掌式」，左手剑诀，右手剑气直刺$n的$l",
	"force"         : 220,
	"dodge"         : 40,
	"damage"        : 250,
	"lvl"           : 100,
	"skill_name"    : "破掌式",
	"damage_type"   : "淤伤"
]),
([      "action" :      "$N右手虚抱成圆，一式「破枪式」，中宫直进，剑气突地刺向$n的$l",
	"force"         : 240,
	"dodge"         : 50,
	"damage"        : 350,
	"lvl"           : 150,
	"skill_name"    : "破枪式",
	"damage_type"   : "刺伤"
]),
([      "action" :      "$N一式「破索式」，$w轻摆，剑气从上至下猛劈，挟爆裂之声骤然斩向$n的$l",
	"force"         : 260,
	"dodge"         : 60,
	"damage"        : 450,
	"lvl"           : 200,
	"skill_name"    : "破索式",
	"damage_type"   : "拉伤"
]),
([      "action" :      "$N运气施出「破鞭式」，逼出一道混元剑气，闪电般破空射向$n的$l",
	"force"         : 280,
	"dodge"         : 70,
	"damage"        : 550,
	"lvl"           : 250,
	"skill_name"    : "破鞭式",
	"damage_type"   : "鞭伤"
]),
([      "action" :      "$N拔步挺腰，一式「破气式」，剑气沉滞无比，缓缓撞向$n的$l",
	"force"         : 300,
	"dodge"         : 80,
	"damage"        : 650,
	"lvl"           : 300,
	"skill_name"    : "破气式",
	"damage_type"   : "拉伤"
]),
([      "action" :      "$N双腿半屈半蹲，一式「破箭式」，剑气划出无数圆圈，狂风骤起，笼罩天地",
	"force"         : 350,
	"dodge"         : 90,
	"damage"        : 750,
	"lvl"           : 350,
	"skill_name"    : "破箭式",
	"damage_type"   : "刺伤"
]),
([      "action" :      "$N一式「总诀式」，剑指并合，虚虚一指，天地无不为之变色",
	"force"         : 400,
	"dodge"         : 100,
	"damage"        : 850,
	"lvl"           : 400,
	"skill_name"    : "总诀式",
	"damage_type"   : "砍伤"
]),
([      "action" : "$N一式「总诀式」，随手一指，无招无式，天地为之变色",
	"force"         : 500,
	"dodge"         : 120,
	"damage"        : 950,
	"lvl"           : 500,
	"skill_name"    : "总诀式",
	"damage_type"   : "刺伤"
]),
});

int master_skill() { return 1;}
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	object ob;

	if( !me->query("is_zongshi"))
		return notify_fail("你还不是武林宗师，不能学习宗师武功。\n");

	if ((int)me->query("max_neili") < 5000)
		return notify_fail("你的内力修为不够，不能学习宗师武功。\n");

	if( !(ob = me->query_temp("weapon"))
	||      (string)ob->query("skill_type") != "sword")
		return notify_fail("你必须先找一把剑才能练独孤剑气。\n");

	if((int)me->query_skill("xuanming-shenzhang",1)
	|| (int)me->query_skill("duanhun-qiang",1)
	|| (int)me->query_skill("ningxue-shenzhua",1))
		return notify_fail("你怎么身兼多种宗师武功呢？\n");

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
	level   = (int) me->query_skill("dugu-jianqi",1);
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"]) return action[random(i)];
}

int practice_skill(object me)
{
	object weapon;

	if( !me->query("is_zongshi"))
		return notify_fail("你还不是武林宗师，不能练习宗师武功。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| weapon->query("skill_type") != "sword")
		return notify_fail("你必须找到一把剑才可以练习独孤剑气。\n");

	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练独孤剑气。\n");

	me->receive_damage("qi", 35);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"dugu-jianqi/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;
	if(me->query_skill("dugu-jianqi",1) > 200
	&& random(me->query("neili")) > victim->query("max_neili")
	&& me->query("neili") > 500 ) {
		message_vision(WHT"只见$N剑光暴长，随着“嗤”的一声轻响，竟是一道剑气在$n的胸口疾划而过！\n"NOR,me,victim);
		victim->receive_wound("jing",(damage_bonus - 100) / 2, me);
		me->add("neili",-300);
		if(!victim->is_busy()) victim->start_busy(1);
		return 1;
	}
}
