// xuanming-shenzhang.c 玄冥神掌

#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N往后一纵，就势使了扫堂腿，双掌却借机反卷而上，长驱直入地击向$n后心！",
	"lvl" : 0,
	"damage_type": "瘀伤"
]),
([      "action": "$N轻轻一纵，与$n错身而过。便在这时，$N的手臂就象没长骨头似的往外一曲，\n快若闪电地击上了$n左腿！",
	"lvl" : 50,
	"damage_type": "瘀伤"
]),
([      "action": "$N接连几个急转，身形如陀螺般向$n滚去，转一圈击一掌，掌掌不离$n的左手！",
	"lvl" : 100,
	"damage_type": "瘀伤"
]),
([      "action": "$N脚下连换几个方位，双掌一错，右手突然暴涨数尺往也许胸口一搭一推！",
	"lvl" : 200,
	"damage_type": "瘀伤"
]),
([      "action": "$N嘿嘿一笑，双掌在空气中划得嗤嗤着响！劲气纵横中突然飞出一掌，\n悄无声息地拍向$n后心！",
	"lvl" : 250,
	"damage_type": "内伤"
]),
([      "action": "只听$N一声清啸，身形如流水，掌势若浮云，暗光流转中延绵不绝地拍向$n周身要害！",
	"lvl" : 300,
	"damage_type": "割伤"
]),
([      "action": "只见$N凝神运气，左手护胸，右手掌心呈暗红，带着一股腥热之气拍向$n左脚！",
	"lvl" : 350,
	"damage_type": "瘀伤"
]),
([      "action": "$N身形一滚，一脚凌空踢出，并不攻敌。左掌却在这一带之下从\n意想不到的角度拍上了$n的右臂！",
	"lvl" : 400,
	"damage_type": "瘀伤"
]),

});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry" || usage=="strike"; }
int valid_learn(object me)
{
	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练玄冥神掌必须空手。\n");

	if(!(int)me->query("is_zongshi"))
		return notify_fail("以你目前的能力，恐怕难以理会玄冥神掌当中的精髓。\n");

	if((int)me->query("max_neili") < 5000)
		return notify_fail("你的内力太弱，无法练玄冥神掌。\n");

	if((int)me->query_skill("duanhun-qiangfa",1)
	|| (int)me->query_skill("dugu-jianqi",1)
	|| (int)me->query_skill("ningxue-shenzhua",1))
		return notify_fail("你怎么身兼多种宗师武功呢？\n");

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
	level   = (int) me->query_skill("xuanming-shenzhang",1);
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
mixed hit_ob(object me, object victim,int damage_bonus)
{
	int skill_level;
	skill_level = (int)me->query_skill("xuanming-shenzhang",1);

	if( damage_bonus < 100 ) return 0;
	if(me->query_temp("weapon") || me->query_temp("secondary_weapon")) return 0;
	if(!me->query_temp("weapon")
	&& !me->query_temp("secondary_weapon")
	&& me->is_fighting(victim) && victim->is_fighting(me)
	&& living(victim) && victim->query("qi") > 0)
	if(random(skill_level)>200 && me->query("neili")>2000){
		me->add("neili",-random(500)-500);
		message_vision(HIG"\n$N突然一声暴喝，双手骤然之间泛起一道青绿之光，五指迅速扩散而开，\n猛然间带着一股阴寒无比之气，朝$n胸口攻去。\n"NOR,me,victim);
		victim->receive_wound("jing",(damage_bonus / 2)- 100, me);
		victim->apply_condition("xuanming_poison",victim->query_condition("xuanming_poison") + skill_level / 5);
		return 1;
	}
}
int practice_skill(object me)
{
	if((int)me->query("qi") < 100)
		return notify_fail("你的体力太低了。\n");

	if((int)me->query("neili") < 100)
		return notify_fail("你的内力不够练玄冥神掌。\n");

	if(!(int)me->query("is_zongshi"))
		return notify_fail("以你目前的能力，恐怕难以理会玄冥神掌当中的精髓。\n");

	me->receive_damage("qi",100);
	me->add("neili", -50);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"xuanming-shenzhang/" + action;
}
