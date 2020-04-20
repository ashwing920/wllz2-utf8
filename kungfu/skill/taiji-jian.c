// taiji-jian.c 太极剑

#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
	"$n左手剑诀斜引，$v横过，画了个半圈，平搭在$N$w之上，劲力传出，$w登时一沉。\n",
	"$n$v交左手，在身前划了两个圆圈，$N见$n剑劲连绵，护住全身，竟无半分空隙。\n",
	"$n剑招未曾使老，已然圈转。突然之间，$N眼前出现了几个白色光圈，大圈小圈，\n正圈斜圈，闪烁不已。$P眼睛一花，只好回招。\n",
	"$n当下凝神专志，将一套太极剑法使得圆转如意，严密异常的守住门户。\n",
	"$n以太极剑中「云麾三舞」三式解开。$N见$n化解时举重若轻，深得内家剑术三昧，\n不待$n回手，跳开一步。\n"
});
string query_parry_msg(object weapon)
{
        if( weapon )
        	return parry_msg[random(sizeof(parry_msg))];
}

mapping *action = ({
([      "action" : "$N虚步提腰，一招「蜻蜓点水」，手中$w轻轻颤动，一剑剑点向$n的$l",
	"force" : 60,
	"dodge" : 20,
	"parry" : 10,
	"damage" : 45,
	"skill_name":"蜻蜓点水",
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，左手剑诀，右手$w使出一式「指南针」直刺$n的$l",
	"force" : 70,
	"dodge" : 15,
	"parry" : 10,
	"damage" : 50,
	"skill_name":"指南针",
	"lvl" : 10,
	"damage_type" : "刺伤"
]),
([      "action" : "$N身形往右一挫，左手剑诀，右手$w使出一式「大魁星」刺向$n的$l",
	"force" : 80,
	"dodge" : 15,
	"parry" : 10,
	"damage" : 50,
	"skill_name":"大魁星",
	"lvl" : 20,
	"damage_type" : "刺伤"
]),
([      "action" : "$N双膝下沉，右手$w使出一式「探海式」，由下而上疾刺$n的$l",
	"force" : 90,
	"dodge" : 15,
	"parry" : 10,
	"damage" : 50,
	"skill_name":"探海式",
	"lvl" : 30,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「燕子掠波」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
	"force" : 100,
	"dodge" : 15,
	"parry" : 15,
	"damage" : 60,
	"skill_name":"燕子掠波",
	"lvl" : 40,
	"damage_type" : "刺伤"
]),
([      "action" : "$N上身往左侧一拧，一招「乌龙摆尾」，右手$w反手向$n的$l挥去",
	"force" : 110,
	"dodge" : 15,
	"parry" : 15,
	"damage" : 70,
	"skill_name":"乌龙摆尾",
	"lvl" : 50,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「右拦扫」，一招「左拦扫」，剑锋平指，一气呵成横扫$n的$l",
	"force" : 120,
	"dodge" : 10,
	"parry" : 15,
	"damage" : 70,
	"skill_name":HIC"左拦扫、右拦扫"NOR,
	"lvl" : 60,
	"damage_type" : "刺伤"
]),
([      "action" : "$N左腿提膝，手中$w斜指，一招「宿鸟投林」刺向$n的$l",
	"force" : 130,
	"dodge" : 15,
	"parry" : 15,
	"damage" : 70,
	"skill_name":HIY"宿鸟投林"NOR,
	"lvl" : 70,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「青龙出水」，$w自下而上划出一个大弧，平平地挥向$n的$l",
	"force" : 140,
	"dodge" : 15,
	"parry" : 15,
	"damage" : 71,
	"skill_name":HIG"青龙出水"NOR,
	"lvl" : 80,
	"damage_type" : "刺伤"
]),
([      "action" : "$N使出「三环套月」，$w划出三个圆圈，剑锋直出，绵绵不断划向$n的$l",
	"force" : 150,
	"dodge" : 10,
	"parry" : 20,
	"damage" : 73,
	"skill_name":HIR"三环套月"NOR,
	"lvl" : 100,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「风卷荷叶」，$w轻灵地划出几个圆弧，迅速地向$n的$l挥去",
	"force" : 160,
	"dodge" : 15,
	"parry" : 20,
	"damage" : 75,
	"skill_name":HIM"风卷荷叶"NOR,
	"lvl" : 120,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「虎抱头」，$w划出一个左低右高的大弧，斜斜地斩向$n的$l",
	"force" : 170,
	"dodge" : 15,
	"parry" : 20,
	"damage" : 77,
	"skill_name":HIY"虎抱头"NOR,
	"lvl" : 140,
	"damage_type" : "刺伤"
]),
([      "action" : "$N使出「狮子摇头」，$w由右向左划出一个大８字，将$n圈在其中",
	"force" : 180,
	"dodge" : 15,
	"parry" : 20,
	"damage" : 79,
	"skill_name":HIW"狮子摇头"NOR,
	"lvl" : 160,
	"damage_type" : "刺伤"
]),
([      "action" : "$N左脚踏实，右脚虚点，一招「仙人指路」，右手$w带着一团剑花，逼向$n的$l",
	"force" : 190,
	"dodge" : 5,
	"parry" : 20,
	"damage" : 81,
	"lvl" : 180,
	"skill_name":HIB"仙人指路"NOR,
	"damage_type" : "刺伤"
]),
([      "action" : "$N轻轻跃起，一招「野马跳涧」，$w在半空中化为一圈银芒，落向$n的$l",
	"force" : 200,
	"dodge" : 15,
	"parry" : 20,
	"damage" : 83,
	"skill_name":HIG"野马跳涧"NOR,
	"lvl" : 190,
	"damage_type" : "刺伤"
]),
([      "action" : "$N两腿前箭后弓，一招「射雁式」，右手$w直刺$n的$l",
	"force" : 210,
	"dodge" : 20,
	"parry" : 20,
	"damage" : 85,
	"skill_name":HIR"射雁式"NOR,
	"lvl" : 200,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「小魁星」，身形往左一挫，左手剑诀，右手$w平平地向$n的$l挥去",
	"force" : 220,
	"dodge" : 40,
	"parry" : 20,
	"damage" : 87,
	"skill_name":WHT"小魁星"NOR,
	"lvl" : 220,
	"damage_type" : "刺伤"
]),
([      "action" : "$N猱身扑上，一招「白猿献果」，手中$w斜斜地向$n的$l挥去",
	"force" : 230,
	"dodge" : 30,
	"parry" : 20,
	"damage" : 89,
	"skill_name":"白猿献果",
	"lvl" : 240,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「迎风掸尘」，$w看似随意地一挥，$n却陡觉一股劲气迎面袭来。",
	"force" : 240,
	"dodge" : 20,
	"parry" : 25,
	"damage" : 91,
	"skill_name":"迎风掸尘",
	"lvl" : 250,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「顺水推舟」，$w自上而下划出一个大弧，平平地向$n的$l挥去。",
	"force" : 250,
	"dodge" : 45,
	"parry" : 25,
	"damage" : 93,
	"skill_name":"顺水推舟",
	"lvl" : 260,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「流星赶月」，$w疾刺$n的$l",
	"force" : 260,
	"dodge" : 35,
	"parry" : 25,
	"damage" : 95,
	"skill_name":"流星追月",
	"lvl" : 270,
	"damage_type" : "刺伤"
]),
([      "action" : "$N突然盘蹲下身来，一招「海底捞月」，$w自下而上地向$n的$l挥去",
	"force" : 270,
	"dodge" : 25,
	"parry" : 25,
	"damage" : 97,
	"skill_name":"海底捞月",
	"lvl" : 280,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「挑帘式」，$w自下而上徐徐划出一个大弧，平平地向$n的$l挥去",
	"force" : 280,
	"dodge" : 35,
	"parry" : 25,
	"damage" : 99,
	"skill_name":"挑帘式",
	"lvl" : 290,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「黄蜂入洞」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
	"force" : 290,
	"dodge" : 40,
	"parry" : 25,
	"damage" : 102,
	"skill_name":"黄蜂入洞",
	"lvl" : 300,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「大鹏展翅」，身形跃起，右手$w刺向$n的$l",
	"force" : 300,
	"dodge" : 45,
	"parry" : 25,
	"damage" : 106,
	"skill_name":"大鹏展翅",
	"lvl" : 320,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「车轮剑」，$w化作一片银盘，平平地向$n的$l卷去",
	"force" : 310,
	"dodge" : 45,
	"parry" : 25,
	"damage" : 120,
	"skill_name":"车轮剑",
	"lvl" : 340,
	"damage_type" : "刺伤"
]),
([      "action" : "$N左脚轻点地面，身形往前一扑，一招「天马行空」，$w向$n的$l挥去",
	"force" : 320,
	"dodge" : 45,
	"parry" : 30,
	"damage" : 125,
	"skill_name":"天马行空",
	"lvl" : 360,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「风扫梅花」，身体跃在半空，手中$w扫向$n的$l",
	"force" : 330,
	"dodge" : 45,
	"parry" : 30,
	"damage" : 130,
	"skill_name":"风扫梅花",
	"lvl" : 380,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「却步抽剑」，左脚跃步落地，$w回抽，反手勾向$n的$l",
	"force" : 340,
	"dodge" : 35,
	"parry" : 30,
	"damage" : 140,
	"skill_name":"却步抽剑",
	"lvl" : 400,
	"damage_type" : "刺伤"
]),
([      "action" : "$N右腿半屈般蹲，一招「如封似闭」，剑尖虚指，转身撩向$n的$l",
	"force" : 350,
	"dodge" : 25,
	"parry" : 30,
	"damage" : 150,
	"skill_name":"如封似闭",
	"lvl" : 440,
	"damage_type" : "刺伤"
]),
([  "action" : "$N回身拧腰，右手虚抱，一招「拨云瞻日」，$w中宫直进，刺向$n的$l",
	"force" : 380,
	"dodge" : 35,
	"parry" : 30,
	"damage" : 160,
	"skill_name":"拨云瞻日",
	"lvl" : 480,
	"damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");

	if((string)me->query("family/family_name") != "明教"
	&& (int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("你的太极神功火候太浅。\n");

	if ((int)me->query_skill("taiji-quan", 1) < 20)
		return notify_fail("你的太极拳火候太浅。\n");

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
	level   = (int) me->query_skill("taiji-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练太极剑法。\n");
	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-jian/" + action;
}
