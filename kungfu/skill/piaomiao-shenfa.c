// piaomiao-shenfa.c 飘渺身法


inherit SKILL;

string *dodge_msg = ({
	"只见$n身随意转，一扭身已飘到$N背后，躲过了这一招。\n",
	"$n运起天魔身法，身影有如疾电流窜，令$N的攻势全数落空。\n",
	"$N只感眼前一花，$n已幻化成无数化身四散飞射。\n"
	"$n身影突如陀螺急转，形成猛烈的气劲漩涡，坚密如墙，$N根本无从入手。\n",
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }
int valid_learn(object me) { return 1; }
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("你的体力太差了，不能练飘渺身法。\n");
	me->receive_damage("qi", 30);
	return 1;
}
