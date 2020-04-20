// xue-dao.c 血刀

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action" : "$N使出一招「磨牙吮血」，把刀咬在口中，只在$n身前身后乱转，\n瞅个破绽，猛地欺身向前，拔出刀来一刀直劈下去",
	"force" : 100,
	"dodge" : -10,
	"parry" : 5,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "磨牙吮血",
	"damage_type" : "割伤"
]),
([	"action" : "$N腰劲运肩，肩通於臂，向前一冲，跨出一步半，攸忽缩脚，\n身形一矮向$n下三路实砍两刀，正是一招「批纸削腐」",
	"force" : 150,
	"dodge" : -10,
	"parry" : 10,
	"damage": 25,
	"lvl" : 12,
	"skill_name" : "批纸削腐",
	"damage_type" : "劈伤"
]),
([	"action" : "$N口发荷荷怪声，手中刀直向前伸，一招「血海茫茫」，\n手中$w直向前伸，将$n的两肩和面门笼罩在刀光之下",
	"force" : 200,
	"dodge" : -5,
	"parry" : 5,
	"damage": 35,
	"lvl" : 20,
	"skill_name" : "血海茫茫",
	"damage_type" : "割伤"
]),
([	"action" : "$N手一扬，一招「流星经天」，手中刀脱手飞出，一溜红光，径向$n的$l飞去",
	"force" : 250,
	"dodge" : 5,
	"parry" : 5,
	"damage": 50,
	"lvl" : 28,
	"skill_name" : "流星经天",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「血踪万里」，身子原地打了一个转, 反手一刀向$n的$l捅了过去",
	"force" : 300,
	"dodge" : 5,
	"parry" : 5,
	"damage": 55,
	"lvl" : 36,
	"skill_name" : "血踪万里",
	"damage_type" : "割伤"
]),
([	"action" : "$N双手反执刀尖，合於怀中，突然左肩微沉，一招「偷云换日」，\n左手从右臂下穿出转移$n的目光，右手执刀猛刺$n的$l",
	"force" : 350,
	"dodge" : -10,
	"parry" : 15,
	"damage": 60,
	"lvl" : 44,
	"skill_name" : "偷云换日",
	"damage_type" : "劈伤"
]),
([	"action" : "$N突然还刀入鞘，蓦地欺近身去，身体半跪，反手抽刀，一式「血洗天河」，\n只见一片匹练也似的刀光从$n下阴直撩至天灵盖",
	"force" : 400,
	"dodge" : 10,
	"parry" : 20,
	"damage": 75,
	"lvl" : 52,
	"skill_name" : "血洗天河",
	"damage_type" : "割伤"
]),
([	"action" : "$N刀尖平指，一招「血流漫面」，刀光霍霍，三横两直，带着阵阵风声砍向$n的面门",
	"force" : 450,
	"dodge" : 5,
	"parry" : 25,
	"damage": 80,
	"lvl" : 60,
	"skill_name" : "血流漫面",
	"damage_type" : "割伤"
]),
});

string *parry_msg = ({
	"$n反手一刺，$v象一条盘蛇，直扑$N的手腕。\n",
	"$n向左侧进一步，手中的$v顺势滑下，急削$N握的手指。\n",
	"$n刀法一变，将手中的$v向上一撩，将$N的攻势引偏出去。\n",
});
string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
}

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="miexian-zhang"; }

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你手中无刀，如何领会血刀的精髓？\n");

	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("xuehai-mogong", 1) < 20)
		return notify_fail("你的血海魔功火候太浅。\n");

	return 1;
		
}
mapping query_action(object me, object weapon)
{
	mapping retval;
	int i, j, level, neili;
	level  = (int) me->query_skill("xue-dao",1);

	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
		      j = NewRandom(i, 20, level/5);
		      break;
		}
	}
	retval = action[j];
	if (random(me->query_skill("blade")) > 150 
	&& ((string)me->query_skill_mapped("force") == "xuehai-mogong")
	&& (int)me->query_skill("force") > 100  && (int)me->query("neili") > 800 ) {
		if(random(10) > 5) {
			retval["damage"] += random((int)me->query_skill("force"))/8;
			me->add("neili", -50);
		}
	}
	return retval;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够，练不了血刀。\n");

	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xue-dao/" + action;
}
