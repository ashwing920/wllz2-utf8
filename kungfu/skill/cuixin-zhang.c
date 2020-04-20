// /kungfu/skill/cuixin-zhang.c

inherit SKILL;

mapping *action = ({
([      "action" : "$N使一招「风起云涌」，双手飘移不定击向$n$l",
	"force" : 160,
	"dodge" : 2,
	"skill_name" : "风起云涌",
	"lvl" : 10,
	"damage_type" : "瘀伤"
]),
([      "action" : "$N倏忽欺至$n身前，一招「扬波起浪」直拍$n的$l",
	"force" : 240,
	"dodge" : 0,
	"skill_name" : "扬波起浪",
	"lvl" : 30,
	"damage_type" : "瘀伤"
]),
([      "action" : "$N身形绕$n一转，一招「风雷并起」向$n$l接连出掌",
	"force" : 320,
	"dodge" : -2,
	"skill_name" : "风雷并起",
	"lvl" : 50,
	"damage_type" : "瘀伤"
]),
([      "action" : "$N身形拔起，在半空一招「急电惊雷」右掌猛击$n的$l",
	"force" : 400,
	"dodge" : -4,
	"skill_name" : "急电惊雷",
	"lvl" : 90,
	"damage_type" : "瘀伤"
]),
([      "action" : "$N使一招「含沙射影」，纵起丈余直击$n的$l",
	"force" : 500,
	"dodge" : -6,
	"skill_name" : "含沙射影",
	"lvl" : 120,
	"damage_type" : "瘀伤"
]),
([      "action" : "$N一声大喝使出「夺魄催心」，幻出满天掌影，掌掌不离$n的$l",
	"force" : 620,
	"dodge" : -8,
	"skill_name" : "夺魄催心",
	"lvl" : 150,
	"damage_type" : "瘀伤"
]),
([      "action" : "$N乘势疾上，双臂直上直下，跟着大喝一声，双掌同时推出",
	"force" : 380,
	"dodge" : 40,
	"damage": 60,
	"lvl" : 200,
	"damage_type" : "内伤"
]),
([	"action" : "$N攸地变爪为掌，身子不动，右臂陡长，潜运内力，一掌朝$n$l劈去",
	"force" : 420,
	"dodge" : 70,
	"damage": 30,
	"lvl" : 280,
	"damage_type" : "内伤"
]),
([	"action" : "$N双掌不住地忽伸忽缩，手臂关节喀喇声响，右掌一立，左掌啪的一下朝$n$l击去",
	"force" : 480,
	"dodge" : 60,
	"damage": 40,
	"lvl" : 340,
	"damage_type" : "内伤"
]),
([	"action" : "$N身形挫动，风声虎虎，接着朝$n连发八掌，一掌快似一掌，一掌猛似一掌",
	"force" : 520,
	"dodge" : 50,
	"damage": 50,
	"lvl" : 460,
	"damage_type" : "淤伤"
]),
([	"action" : "$N一声怪啸，形如飘风，左掌已如风行电挚般拍出，掌未到，风先至，迅猛已极",
	"force" : 550,
	"dodge" : 30,
	"damage": 70,
	"lvl" : 580,
	"damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练催心掌必须空手。\n");
	if ((int)me->query_skill("bibo-shengong", 1) < 20)
		return notify_fail("你的碧波神功火候不够，无法学催心掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练催心掌。\n");
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
	level = (int)me->query_skill("cuixin-zhang",1);
		for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]){
		a_action = action[NewRandom(i, 20, level/5)];
		break;
				}
	a_action["dodge"]  = 0-level/4;
	a_action["force"] = level*3;
	a_action["attack"] = level*3;
	a_action["parry"] = level;
	a_action["damage"] = level*4;
	a_action["weapon"] = random(2)?"催心掌的掌力":"催心掌的掌风";
	a_action["damage_type"] = random(2)?"震伤":"挫伤";
	return a_action;

}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练催心掌。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"cuixin-zhang/" + action;
}

