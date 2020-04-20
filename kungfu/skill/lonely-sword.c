// lonely-sword.c 独孤九剑
#include <ansi.h>

inherit SKILL;

string *parry_msg = ({
	"却见$n踏前一步，剑式斜指你的右臂，想要使$P闪身而退。\n",
	"$n以攻为守，以进为退，凝神运气向$P猛攻快打地挥出方位大异的泰山「快活三」三剑。\n",
	"$n剑法突变，剑势伸缩不定，奔腾矫夭，逆使嵩山剑法的「天外玉龙」企图迫使$P变招。\n",
	"$n突然一剑点向$P的$l，虽一剑却暗藏无数后着，$P手足无措，攻势不由自主停了下来！\n"
	"$n不闪不避，举剑闪电般使出「叠翠浮青」反削$P的$l，想挡过你此招。\n",
	"$n突然使出青城派松风剑法的「鸿飞冥冥」，可是方位却有所偏差，长剑对着$P一绞，\n企图突破$P的攻势！\n"
	"$n挺剑一招象是「白云出岫」回刺$P的$l，企图将$P的攻势化解。\n",
	"只见$n不退反进，身如飘风，诡异地一式「天柱云气」，动向无定不可捉摸地挡住了$P的\n进攻。\n",
	"$n不退反进，使出恒山剑招「绵里藏针」，森森剑气充溢四周！拒开了$P的这招\n",
});

mapping *action = ({
([      "action" : "但见$N挺身而上，$w一旋，一招仿佛泰山剑法的「来鹤清泉」直刺$n的$l！",
	"force" : 50,
	"dodge" : 5,
	"damage": 60,
	"lvl" : 10,
	"skill_name":"来鹤清泉",
	"damage_type" : "刺伤"
]),
([      "action" : "$N奇诡地向$n挥出「泉鸣芙蓉」、「鹤翔紫盖」、「石廪书声」、\n「天柱云气」及「雁回祝融」衡山五神剑！",
	"force" : 60,
	"dodge" : 0,
	"damage": 90,
	"lvl" : 30,
	"skill_name":"衡山五神剑",
	"damage_type" : "刺伤"
]),
([
	"action" : "$N剑随身转，续而刺出十九剑，竟然是华山「玉女十九剑」，\n但奇的是这十九剑便如一招，手法之快，直是匪夷所思！",
	"force" : 70,
	"dodge" : 5,
	"damage": 120,
	"lvl" : 50,
	"skill_name":"玉女十九剑",
	"damage_type" : "刺伤"
]),
([      "action" : "$N剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向$n慢慢推去！",
	"force" : 80,
	"dodge" : 15,
	"damage": 150,
	"lvl" : 80,
	"damage_type" : "刺伤"
]),
([      "action" : "$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里，尽括嵩山剑势击向$n的$l！",
	"force" : 90,
	"dodge" : 0,
	"damage": 180,
	"lvl" : 100,
	"damage_type" : "刺伤"
]),
([      "action" : "却见$N身随剑走，左边一拐，右边一弯，剑招也是越转越加狠辣，\n竟化「泰山十八盘」为一剑攻向$n！",
	"force" : 100,
	"dodge" : 10,
	"damage": 210,
	"lvl" : 130,
	"skill_name":"泰山十八盘",
	"damage_type" : "刺伤"
]),
([      "action" : "$N剑招突变，使出衡山的「一剑落九雁」，削向$n的$l，\n怎知剑到中途，突然转向，大出$n意料之外！",
	"force" : 110,
	"dodge" : 5,
	"damage": 240,
	"lvl" : 140,
	"skill_name":"一剑落九雁",
	"damage_type" : "刺伤"
]),
([      "action" : "$N吐气开声，一招似是「独劈华山」，手中$w向下斩落，直劈向$n的$l！",
	"force" : 120,
	"dodge" : 0,
	"damage": 270,
	"lvl" : 150,
	"skill_name":"独劈华山",
	"damage_type" : "刺伤"
]),
([      "action" : "$N手中$w越转越快，使的居然是衡山的「百变千幻云雾十三式」，\n剑式有如云卷雾涌，旁观者不由得目为之眩！",
	"force" : 140,
	"dodge" : 20,
	"damage": 300,
	"lvl" : 160,
	"skill_name":"云雾十三式",
	"damage_type" : "刺伤"
]),
([      "action" : "$N含笑抱剑，气势庄严，$w轻挥，尽融「达摩剑」为一式，闲舒地刺向$n！",
	"force" : 160,
	"dodge" : 0,
	"damage": 330,
	"lvl" : 170,
	"damage_type" : "刺伤"
]),
([      "action" : "$N举起$w运使「太极剑」剑意，划出大大小小无数个圆圈，无穷无尽源源不绝地缠向$n！",
	"force" : 180,
	"dodge" : 20,
	"damage": 360,
	"lvl" : 180,
	"skill_name":"太极圈",
	"damage_type" : "刺伤"
]),
([      "action" : "$N神声凝重，$w上劈下切左右横扫，挟雷霆万钧之势逼往$n，「伏摩剑」的剑意表露无遗！",
	"force" : 200,
	"dodge" : 5,
	"damage": 390,
	"lvl" : 190,
	"skill_name":"伏魔式",
	"damage_type" : "刺伤"
]),
([      "action" : "却见$N突然虚步提腰，使出酷似武当「蜻蜓点水」的一招！",
	"force" : 220,
	"dodge" : 15,
	"damage": 420,
	"lvl" : 200,
	"skill_name":"蜻蜓点水",
	"damage_type" : "刺伤"
]),
([      "action" : "$N运剑如风，剑光霍霍中反攻$n的$l，尝试逼$n自守，剑招似是「伏魔剑」的「龙吞式」。",
	"force" : 240,
	"dodge" : 0,
	"damage": 450,
	"lvl" : 210,
	"skill_name":"龙吞式",
	"damage_type" : "刺伤"
]),
([      "action" : "$N突然运剑如狂，一手关外的「乱披风剑法」，猛然向$n周身乱刺乱削！",
	"force" : 260,
	"dodge" : 15,
	"damage": 480,
	"lvl" : 220,
	"skill_name":"乱披风剑法",
	"damage_type" : "刺伤"
]),
([      "action" : "$N满场游走，东刺一剑，西刺一剑，令$n莫明其妙，分不出$N剑法的虚实！",
	"force" : 280,
	"dodge" : 30,
	"damage": 500,
	"lvl" : 240,
	"damage_type" : "刺伤"
]),
([      "action" : "$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是什么剑法！",
	"force" : 320,
	"dodge" : 5,
	"damage": 520,
	"lvl" : 260,
	"damage_type" : "刺伤"
]),
([      "action" : "$N突然一剑点向$n的$l，虽一剑却暗藏无数后着，$n手足无措，不知如何是好！",
	"force" : 360,
	"dodge" : 0,
	"damage": 550,
	"lvl" : 280,
	"damage_type" : "刺伤"
]),
([      "action" : "$N剑挟刀势，大开大阖地乱砍一通，但招招皆击在$n攻势的破绽，迫得$n不得不守！",
	"force" : 380,
	"dodge" : 20,
	"damage": 570,
	"lvl" : 300,
	"skill_name":"刀剑合一",
	"damage_type" : "刺伤"
]),
([      "action" : "$N反手横剑刺向$n的$l，这似有招似无招的一剑，威力竟然奇大，$n难以看清剑招来势！",
	"force" : 400,
	"dodge" : 15,
	"damage": 580,
	"lvl" : 320,
	"damage_type" : "刺伤"
]),
([      "action" : "$N举剑狂挥，迅速无比地点向$n的$l，却令人看不出其所用是什么招式。",
	"force" : 450,
	"dodge" : 0,
	"damage": 590,
	"lvl" : 440,
	"skill_name":"狂风乱舞",
	"damage_type" : "刺伤"
]),
([      "action" : "$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不可思议！",
	"force" : 500,
	"dodge" : 40,
	"damage": 600,
	"lvl" : 470,
	"damage_type" : "刺伤"
]),
([      "action" : HIW"$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向$n的$l！"NOR,
	"force" : 550,
	"dodge" : 20,
	"damage": 620,
	"lvl" : 500,
	"damage_type" : "刺伤"
]),
([
	"action" : HIW"$N将$w随手一摆，但见$n自己向$w撞将上来，神剑之威，实人所难测！"NOR,
	"force" : 600,
	"dodge" : 50,
	"damage": 640,
	"lvl" : 600,
	"skill_name":"威震八方",
	"damage_type" : "刺伤"
])
});

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

//mapping query_action(object me, object weapon)
//{
//	return action[random(sizeof(action))];
//}

mapping query_action(object me, object weapon)
{
	mapping a_action;
	int i, level;
	level = (int)me->query_skill("lonely-sword",1);
		for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]){
		a_action = action[NewRandom(i, 20, level/5)];
		break;
				}
	a_action["dodge"]  = 0-level;
	a_action["parry"] = 0-level;
	a_action["attack"] = level*3;
	a_action["damage"] = level*3;
	return a_action;
}

string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
	object ob;

	mapping myfam;
	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "华山剑派"|| myfam["master_id"] != "feng qingyang")
		return notify_fail("独孤九剑只有向风清扬老前辈学习。\n");
	if((int)me->query("max_neili") < 600 )
		return notify_fail("你的内力不够，没有办法练独孤九剑。\n");
	if((int)me->query_skill("huashan-neigong",1) < 100)
		return notify_fail("独孤九剑必须配合华山内功才能练习。\n");
	if(!(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	if ((int)me->query_skill("lonely-sword",1) >= 300)
		return notify_fail("独孤九剑只能通过「总诀式」来演练。\n");
		return 1;
}
int practice_skill(object me)
{
	return notify_fail("独孤九剑只能通过「总诀式」来演练。\n");
}
string perform_action_file(string action)
{
	return __DIR__"lonely-sword/" + action;
}
