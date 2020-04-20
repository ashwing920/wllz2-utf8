//duanhun-qiang.c
// 断魂枪法

inherit SKILL;

mapping *action = ({
([
	"action":       "$N使一招「周身皆梦」，手中$w一抖，化出无数枪头，直刺$n的$l",
	"dodge":        620,
	"parry":        500,
	"force":        100,
	"damage":       100,
	"lvl":          50,
	"damage_type":  "刺伤",
	"skill_name":   "周身皆梦",
]),
([
	"action":       "$N使出断魂枪中的「执梦为真」，手中$w晃动，虚点数枪，突然自影中发出一枪，刺向$n的$l",
	"dodge":        620,
	"parry":        600,
	"force":        200,
	"damage":       200,
	"lvl":          150,
	"damage_type":  "割伤",
	"skill_name":   "执梦为真",
]),
([      "action":       "$N一招「诸皆成梦」，向前猛窜，手中$w反背一枪，直扎$n的$l",
	"dodge":        630,
	"parry":        400,
	"force":        50,
	"damage":       400,
	"lvl":          250,
	"damage_type":  "割伤",
	"skill_name":   "诸皆成梦",
]),
([      "action":       "$N手中$w一式「梦中知梦」，手中$w枪头乱抖，铺天盖地杀来，枪枪不离$n的$l",
	"force":        90,
	"dodge":        230,
	"parry":        400,
	"damage":       600,
	"lvl":          350,
	"damage_type":  "刺伤",
	"skill_name":   "梦中知梦",
]),
([      "action":       "$N的$w虚点，蓦地进步跟身，一招「观物达观」刺向$n的$l",
	"dodge":        200,
	"parry":        300,
	"force":        300,
	"damage":       800,
	"lvl":          450,
	"damage_type":  "刺伤",
	"skill_name":   "观物达观",
]),
([      "action":       "$N手中$w一递，枪身竟如残月般弯转，一招「一念回光」反手对准$n$l一枪刺去",
	"dodge":        260,
	"parry":        330,
	"force":        100,
	"damage":       1000,
	"lvl":          550,
	"damage_type":  "刺伤",
	"skill_name":   "一念回光",
]),
});

int valid_learn(object me)
{
	object ob;

	if(!me->query("is_zongshi"))
		return notify_fail("你还不是武林宗师，不能学习宗师武功。\n");

	if( (int)me->query("max_neili") < 5000 )
		return notify_fail("你的内力修为不够，没有办法练断魂枪。\n");

	if( !(ob = me->query_temp("weapon"))
	||      (string)ob->query("skill_type") != "spear")
		return notify_fail("你必须先找一把枪才能练枪法。\n");

	if((int)me->query_skill("xuanming-shenzhang",1)
	|| (int)me->query_skill("dugu-jianqi",1)
	|| (int)me->query_skill("ningxue-shenzhua",1))
		return notify_fail("你怎么身兼多种宗师武功呢？\n");

	return 1;
}

int valid_enable(string usage){ return usage=="spear" || usage=="parry";}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("duanhun-qiang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	||      (int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够，没有办法练习断魂枪。\n");
	me->receive_damage("qi", 30);
	me->add("neili",-30);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"duanhun-qiang/" + action;
}
string *parry_msg = ({
	"$n使出一招「过眼烟云」，手中的$v荡开了$N的$w。\n",
	"$n使出「梦中说梦」，将$N的$w封于丈外。\n",
	"$n使出一招「踏遍天涯」，手中的$v化做漫天残照，荡开了$N的$w。\n",
	"$n手中的$v一抖，一招「久历歧途」，向$N拿$w的手腕刺去。\n",
});
string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
}
