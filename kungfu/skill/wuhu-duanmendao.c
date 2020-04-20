// wuhu-duanmendao.c 五虎断门刀

inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w斜指，一招「直来直去」，反身一顿，一刀向$n的$l撩去",
	"force" : 120,
	"dodge" : -10,
	"parry" : 5,
	"damage" : 15,
	"lvl":   0,
	"skill_name":"直来直去",
	"damage_type" : "割伤"
]),
([      "action" : "$N一招「童子挂画」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
	"force" : 130,
	"dodge" : -10,
	"parry" : 10,
	"damage" : 20,
	"lvl":  10,
	"skill_name":"童子挂画",
	"damage_type" : "割伤"
]),
([      "action" : "$N展身虚步，提腰跃落，一招「推窗望月」，刀锋一卷，拦腰斩向$n",
	"force" : 140,
	"dodge" : -5,
	"parry" : 5,
	"damage" : 25,
	"lvl":   20,
	"skill_name":"推窗望月",
	"damage_type" : "割伤"
]),
([      "action" : "$N一招「力劈华山」，$w大开大阖，自上而下划出一个闪电，直劈向$n",
	"force" : 160,
	"dodge" : 5,
	"parry" : 5,
	"damage" : 30,
	"lvl":  40,
	"skill_name":"力劈华山",
	"damage_type" : "割伤"
]),
([      "action" : "$N手中$w一沉，一招「临溪观鱼」，双手持刃拦腰反切，砍向$n的胸口",
	"force" : 180,
	"dodge" : 10,
	"parry" : 5,
	"damage" : 35,
	"lvl":  60,
	"skill_name":"临溪观鱼",
	"damage_type" : "割伤"
]),
([      "action" : "$N挥舞$w，使出一招「张弓望的」，上劈下撩，左挡右开，齐齐罩向$n",
	"force" : 210,
	"dodge" : 15,
	"parry" : 15,
	"damage" : 45,
	"lvl": 80,
	"skill_name":"张弓望的",
	"damage_type" : "割伤"
]),
([      "action" : "$N一招「风送轻舟」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
	"force" : 240,
	"dodge" : 5,
	"parry" : 15,
	"damage" : 50,
	"lvl": 100,
	"skill_name":"风送轻舟",
	"damage_type" : "劈伤"
]),
([      "action" : "$N盘身驻地，一招「川流不息」，挥出一片流光般的刀影，向$n的全身涌去",
	"force" : 280,
	"dodge" : 20,
	"parry" : 10,
	"damage" : 60,
	"lvl": 120,
	"skill_name":"川流不息",
	"damage_type" : "刺伤"
]),
([      "action" : "$N右手后撤，手腕一翻，一招「壮士断腕」，顿时一道白光直斩向$n的手臂",
	"force" : 320,
	"dodge" : 20,
	"parry" : 20,
	"damage" : 70,
	"lvl": 150,
	"skill_name":"壮士断腕",
	"damage_type" : "砍伤"
]),
([      "action" : "$N高高跃起，一招「人头落地」，手中$w直劈向$n的颈部",
	"force" : 320,
	"dodge" : 20,
	"parry" : 20,
	"damage" : 70,
	"lvl":  180,
	"skill_name":"人头落地",
	"damage_type" : "劈伤"
]),
([      "action" : "$N贴地滑行，一招「断子绝孙」，手中$w直撩去$n的裆部",
	"force" : 350,
	"dodge" : 30,
	"parry" : 30,
	"damage" : 80,
	"lvl": 220,
	"skill_name":"断子绝孙",
	"damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("blade", 1) < 20)
		return notify_fail("你的基本刀法火候太浅。\n");
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
	level   = (int) me->query_skill("wuhu-duanmendao",1);
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"]) return action[random(i)];
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练五虎断门刀法。\n");
	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wuhu-duanmendao/" + action;
}

