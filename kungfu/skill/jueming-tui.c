//Cracked by Kafei
// jueming-tui.c

inherit SKILL;

mapping *action = ({
([      "action": "$n用右脚钩踢$N左脚下盘，$N提脚避开$n锋芒，一招「黑虎蹬山」，迅速猛力地连续踹击$n的$l。",
	"dodge": 10,
	"force": 200,
	"damage_type": "瘀伤",
	"skill_name":"黑虎蹬山",
]),
([      "action": "$n右拳击$N头部，$N上体后闪，同时起右脚猛蹬$n腹部，「白猿登枝」，突然变侧踹腿猛力踹击$n$l。",
	"dodge": 25,
	"force": 180,
	"damage_type": "瘀伤",
	"skill_name":"白猿登枝",
]),
([      "action": "$N左拳撩拨$n拳头，右脚内侧踩击$n的胫骨，一招「虎尾搅林」侧踹腿攻击$n$l",
	"dodge": -40,
	"force": 120,
	"damage_type": "瘀伤",
	"skill_name":"虎尾搅林",
]),
([      "action": "$N用右脚钩踢$n左腿下盘，同时右钩踢突然横扫$n腰部，一招「风卷残叶」",
	"dodge": -50,
	"force": 160,
	"damage_type": "瘀伤",
	"skill_name":"风卷残叶",
]),
([      "action": "$n用右拳猛击$N面部，$N速用右里合腿挂拦$n腕部，一招「疾浪翻花」，变为侧踹腿踹$n的$l",
	"dodge": 60,
	"force": 200,
	"damage_type": "瘀伤",
	"skill_name":"疾浪翻花",
]),
([      "action": "$N突发右腿弹踢$n裆部，「浪子踢球」，右腿速变点脚猛力踢击$n之$l",
	"dodge": 70,
	"force": 250,
	"damage_type": "瘀伤",
	"skill_name":"浪子踢球",
]),
([      "action": "$N用右脚钩踢$n足根，使出「顺风扯旗」，顺势变为横腿，侧倒疾扫$n$l",
	"dodge": 80,
	"force": 100,
	"damage_type": "瘀伤",
	"skill_name":"顺风扯旗",
]),
([      "action": "$N起右脚弹踢$n档部，一招「野马奔蹄」，弹踢之腿疾变为侧踹腿，猛力攻击$n$l",
	"dodge": 90,
	"force": 300,
	"damage_type": "瘀伤",
	"skill_name":"野马奔蹄",
]),
});
int valid_enable(string usage) { return  usage=="leg"; }
int valid_combine(string combo) { return combo=="yingxiong-sanzhao"; }
int valid_learn(object me)
{
	if ((int)me->query_skill("shenlong-xinfa", 1) < 20)
		return notify_fail("你的神龙心法火侯不够，无法学绝命腿。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练绝命腿。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 40)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练绝命腿。\n");
	me->receive_damage("jing", 30);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jueming-tui/" + action;
}
