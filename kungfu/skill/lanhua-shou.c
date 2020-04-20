// lanhua-shou.c -兰花拂穴手

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N右手五指分开，微微一拨，再并拢向外一拂，一式「花疏云淡」，拂向$n的膻中要穴",
	"force" : 150,
	"dodge" : 5,
	"damage_type" : "瘀伤",
	"lvl" : 0,
	"skill_name" : "花疏云淡"
]),
([	"action" : "$N侧身掠向$n，一式「轻云蔽月」，左手五指暗暗运气拨向$n的胸前大穴",
	"force" : 160,
	"dodge" : 5,
	"damage_type" : "瘀伤",
	"lvl" : 10,
	"skill_name" : "轻云蔽月"
]),
([	"action" : "$N使一式「云破月来」，左掌虚攻，右手并指斜前翻出，拍向$n的肩井穴",
	"force" : 170,
	"dodge" : 15,
	"damage_type" : "内伤",
	"lvl" : 20,
	"skill_name" : "云破月来"
]),
([	"action" : "$N左掌护胸，微微侧身，右掌勾上，一式「幽兰弄影」，缓缓拂向$n的天突穴",
	"force" : 190,
	"dodge" : -5,
	"damage_type" : "瘀伤",
	"lvl" : 30,
	"skill_name" : "幽兰弄影"
]),
([	"action" : "$N使一式「芳兰竟体」，身影不定地掠至$n身后，猛地拍向$n的大椎穴",
	"force" : 210,
	"dodge" : 10,
	"damage_type" : "瘀伤",
	"lvl" : 42,
	"skill_name" : "芳兰竟体"
]),
([	"action" : "$N两臂左手下右手上地于胸前成兰花指形翻上，微吸一口气，一式「兰桂齐芳」，\n双手向外快速一拨，激出数道劲气逼向$n的华盖、璇玑、紫宫几处大穴",
	"force" : 240,
	"dodge" : 5,
	"damage_type" : "瘀伤",
	"lvl" : 54,
	"skill_name" : "兰桂齐芳"
]),
([	"action" : "$N衣袂飘飘，向上跃起，一式「月影花香」，居高临下，拂出一道劲力罩向$n的百会大穴",
	"force" : 270,
	"dodge" : 20,
	"damage_type" : "内伤",
	"lvl" : 66,
	"skill_name" : "月影花香"
]),
([	"action" : "$N凝神施展出「花好月圆」，双手疾拂，一环环的劲气逼向$n的上中下各大要穴",
	"force" : 300,
	"dodge" : 25,
	"damage_type" : "内伤",
	"lvl" : 80,
	"skill_name" : "花好月圆"
])
});

int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }	 

int valid_combine(string combo) { return combo=="tanzhi-shentong"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练兰花拂穴手必须空手。\n");
	if ((int)me->query_skill("bibo-shengong", 1) < 20)
		return notify_fail("你的碧波神功火候不够，无法学兰花拂穴手。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力太弱，无法练兰花拂穴手。\n");
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
	int i, level;
	level = (int)me->query_skill("lanhua-shou", 1);
	for(i = sizeof(action); i > 0; i--)
	if(level > action[i-1]["lvl"])
	return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
	   return notify_fail("你的体力太低了，无法练兰花拂穴手。\n");
	me->receive_damage("qi", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"lanhua-shou/" + action;
}

