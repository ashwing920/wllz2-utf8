// shenghuo-ling.c 圣火令法

inherit SKILL;

mapping *action = ({
([
	"action": "$N踏上一步，忽地在地上一坐，已抱住了$n小腿。十指扣住了$n小腿上的‘中都’\n‘筑宾’两穴，$n只觉下半身酸麻难动，大吃一惊",
	"dodge": -10,
	"damage": 30,
	"damage_type": "挫伤"
]),
([      "action": "突然之间，$N身形晃动，同时欺近，手中$w往$n身上划去。脚下不知如何移动，\n身形早变。右手同时抓住$n后领，一抖之下，将$n向外远远掷了出去",
	"dodge": -20,
	"damage": 50,
	"damage_type": "挫伤"
]),
([      "action": "$N欺身直进，左手持$w向$n天灵盖上拍落。便在这一瞬之间，$n滚身向左，\n已然一拳打在$n腿上。$n一个踉跄，$N横过$w戳向$n后心",
	"dodge": -30,
	"damage": 70,
	"damage_type": "刺伤"
]),
([      "action": "$N忽地放手，手中那柄$w尾端向上弹起，拍的一响，正好打中$n手腕。",
	"dodge": -20,
	"damage": 90,
	"damage_type": "刺伤"
]),
([      "action": "$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口一痛，已被$N手肘撞中",
	"dodge": -20,
	"damage": 110,
	"damage_type": "瘀伤"
]),
([      "action": "$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，\n突觉胸口$N手中$w急挥横扫，突然连翻三个空心筋斗。$n不知对方是何用意，\n心想还是避之为妙，刚向左踏开一步，眼前白光急闪，$N的$w已到右肩",
	"dodge": -20,
	"damage": 130,
	"damage_type": "挫伤"
]),
([      "action": "$N忽然低头，一个头锤向$n撞来，$n不动声色，向旁又是一让，突觉胸口一痛，已被$N手肘撞中",
	"dodge": -20,
	"damage": 150,
	"damage_type": "挫伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry" || usage =="blade" || usage == "staff" || usage == "club"; }

mapping query_action(object me, object weapon)
{
	if (random(me->query_skill("sword",1)) > 60 &&
	(int)me->query_skill("shenghuo-shengong",1) > 60 &&
	(int)me->query("neili") > 100 && (string)weapon->query("id") == "shenghuo ling" ) {
		me->add("neili", -100);
	return ([
		"action": "$N眼中射出一道青芒，飞身而前，手中圣火令相互一击，铮的一响，\n$n心神一荡，身子从半空中直堕下来，但觉腰胁中一阵疼痛，已被$N踢中了一脚。\n砰的一下，$N的圣火令却又击中了$n的$l",
		"damage": 500,
		"damage_type": "刺伤"
		]);
	}
	return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("qiankun-danuoyi", 1);

	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你先天不足，再学下去难免走火入魔。\n");

	if ((int)me->query("max_neili") < 50)
		return notify_fail("就这么点内力还想学圣火令法？\n");

	if ((int)me->query_skill("shenghuo-shengong",1) < 20)
		return notify_fail("你的圣火神功火候还不够，学不了圣火令法！\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练圣火令法。\n");
		me->receive_damage("qi", 40);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"shenghuo-ling/" + action;
}
