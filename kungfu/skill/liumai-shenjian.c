// liumai-shenjian.c 六脉神剑

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([
	"action" :"$N将右掌按在左臂上，真气急转聚于右手小指，一招「"+RED+"少泽剑"+NOR+"」，一股森寒的剑气刺向$n的$l",
	"lvl" : 0,
	"skill_name" : "少泽剑",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N右手五指微曲，真气随心而至，无名指「"+HIW+"少冲剑"+NOR+"」虚点三下，指端劲气破空而出，射向$n的胸前",
	"lvl" : 10,
	"skill_name" : "少冲剑",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N身形一跃，气与心通，中指轻弹，随意使出一招「"+MAG+"中冲剑"+NOR+"」，\n一股强劲正大的剑气破空射向$n的$l",
	"lvl" : 20,
	"damage_type" : "刺伤"
]),
([
	"action" : "$N身形一侧，左手「"+YEL+"关冲剑"+NOR+"」，轻轻地向$n射去，动作潇洒，\n浑不带一丝杀气，却听到剑气'嗤'的一声划破空气",
	"lvl" : 30,
	"skill_name" : "关冲剑",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N右手食指连点，使出「"+CYN+"少商剑"+NOR+"」，指端真气激荡，如虚如幻地刺至$n的$l",
	"lvl" : 42,
	"skill_name" : "少商剑",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N大喝一声，拇指一扬丹田真气汹涌而至，使出「"+BLU+"商阳剑"+NOR+"」捺向$n，\n刹时间剑气纵横，便似有无数迅雷疾风相互冲撞激",
	"lvl" : 56,
	"skill_name" : "商阳剑",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N身法忽然加快，右手「"+HIG+"少冲剑"+NOR+"」连点把$n的退路全部封杀，左手「"+MAG+"少商剑"+NOR+"」急按$n胸口",
	"lvl" : 72,
	"skill_name" : "晦心一剑",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N猛喝一声，聚起全身功力，双手拇指一并，一股炽热刚猛的剑气如炮弹般射向$n，\n刹时间无数迅雷疾风，相互冲撞激，威不可当",
	"lvl" : 90,
	"skill_name" : "双阳合璧",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N真气急运九大周天，全身真气充盈，不吐不快，右手「"+MAG+"少泽剑"+NOR+"」、「"+RED+"少冲剑"+NOR+"」、\n「"+HIC+"中冲剑"+NOR+"」、一起刺向$n",
	"lvl" : 120,
	"skill_name" : "飘渺三剑",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N默运真气，左手虚指，右手一挥「"+YEL+"商阳剑"+NOR+"」刺向$n",
	"lvl" : 150,
	"skill_name" : "商阳剑",
	"damage_type" : "刺伤"
]),

([
	"action" : "$N杀红了眼，拼尽所有功力，「"+BLU+"少泽剑"+NOR+"」、「"+YEL+"商阳剑"+NOR+"」、「"+WHT+"少冲剑"+NOR+"」、「"+RED+"中冲剑"+NOR+"」、\n「"+HIC+"少商剑"+NOR+"」、「"+CYN+"关冲剑"+NOR+"」一阴一阳，一奇一正，一上一下地射向$n的$l",
	"lvl" : 180,
	"skill_name" : "伍福临门",
	"damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage == "parry" || usage == "finger"; }
int valid_learn(object me)
{
	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练六脉神剑必须空手。\n");
	if((int)me->query_skill("kurong-changong", 1) < 10)
		return notify_fail("你的基本内功火候不够，无法学六脉神剑。\n");
	if((int)me->query("max_neili") < 300)
		return notify_fail("你的内力太弱，无法练六脉神剑。\n");
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
	mapping a_action;
	int i, level;
	level   = (int) me->query_skill("liumai-shenjian", 1);
		for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]){
		a_action = action[NewRandom(i, 20, level/5)];
		break;
				}
	a_action["dodge"]  = 0-level/3;
	a_action["parry"]  = 0-level*3;
	a_action["attack"]  = level/2;
	a_action["force"] = level*3;
	a_action["damage"] = level*4;
	return a_action;

}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练六脉神剑必须空手。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 80)
		return notify_fail("你的内力不够练六脉神剑!\n");
	me->receive_damage("qi", 40);
	me->add("neili", -70);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"liumai-shenjian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;
	if(me->query_temp("weapon") || me->query_temp("secondary_weapon")) return 0;
	if(me->query_skill("liumai-shenjian",1)>100
	&& me->query_skill("kurong-changong",1)> 100)
	if(random((int)me->query("neili")) > (int)victim->query("max_neili") ) {
		victim->receive_wound("qi", (damage_bonus - 100) / 2 , me);
		message_vision(HIR"你听到“嗤”的一声轻响，竟然是剑气在$n的身体对穿而过！\n"NOR,me,victim);
		return 1;
  }
}
