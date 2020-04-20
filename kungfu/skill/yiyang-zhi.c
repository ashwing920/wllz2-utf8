// yiyang-zhi  一阳指

inherit SKILL;

mapping *action = ({
([	"action" : "$N双指并拢，一式「佛恩济世」，和身而上，左右手一前一后戳向$n的胸腹间",
	"force" : 60,
	"dodge" : -5,
	"parry" : -5,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "佛恩济世",
	"damage_type" : "刺伤"
]),
([	"action" : "$N左掌护胸，一式「佛光普照」，右手中指前后划了个半弧，猛地一甩，疾点$n的$l",
	"force" : 120,
	"dodge" : 5,
	"parry" : 10,
	"damage": 20,
	"lvl" : 10,
	"skill_name" : "佛光普照",
	"damage_type" : "刺伤"
]),
([	"action" : "$N身形闪动，一式「佛门广渡」，双手食指端部各射出一道青气，射向$n的全身要穴",
	"force" : 180,
	"dodge" : 10,
	"parry" : 20,
	"damage": 30,
	"lvl" : 20,
	"skill_name" : "佛门广渡",
	"damage_type" : "刺伤"
]),
([	"action" : "$N盘膝跌坐，一式「菩提悟佛」，左手握拳托肘，右手拇指直立，遥遥对着$n一捺",
	"force" : 240,
	"dodge" : 20,
	"parry" : 30,
	"damage": 40,
	"lvl" : 30,
	"skill_name" : "菩提悟佛",
	"damage_type" : "刺伤"
]),
([	"action" : "$N忽地跃起，左掌抚胸，右手伸出食指，一式「佛法无边」缓缓向$n头顶百汇穴点去",
	"force" : 300,
	"dodge" : 30,
	"parry" : 40,
	"damage": 50,
	"lvl" : 40,
	"skill_name" : "佛法无边",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一式「佛现灵山」，出指舒缓自如，收臂潇洒飘逸，对着$n一捺",
	"force" : 360,
	"dodge" : 40,
	"parry" : 50,
	"damage": 60,
	"lvl" : 50,
	"skill_name" : "佛现灵山",
	"damage_type" : "刺伤"
]),
([	"action" : "$N手臂颤动，有如蜻蜒点水，一招「观音济世」，拂遍$n全身诸穴",
	"force" : 420,
	"dodge" : 40,
	"parry" : 50,
	"damage": 70,
	"lvl" : 60,
	"skill_name" : "观音济世",
	"damage_type" : "刺伤"
]),
([	"action" : "$N倏忽之间欺近身去，一招「佛光轻逝」点向$n，一攻而退，鱼逝兔脱，灵动无比",
	"force" : 480,
	"dodge" : 60,
	"parry" : 60,
	"damage": 90,
	"lvl" : 80,
	"skill_name" : "佛光轻逝",
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一阳指必须空手。\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力太弱，无法练一阳指。\n");
	if (me->query_skill("force",1)<20)
		return notify_fail("你的基本内功火候不到，无法练这门功夫。\n");
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
	level   = (int) me->query_skill("yiyang-zhi", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[random(i)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够了。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

int enable_factor() { return 20; }

int learn_bonus() { return 10; }

int practice_bonus() { return 10; }

int study_bonus() { return 10; }