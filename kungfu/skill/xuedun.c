// lingboweibu.c 雪遁

inherit SKILL;

string *dodge_msg = ({
	"只见$n借地势一钻,轻松躲过$N这一招。\n",
	"但是$n忽然消失,出现在敌人背后,避开了$N的攻击。\n",
	"然而$n平躺地上，反使$N的攻势全部落空。\n"
	"但是$n身形欲倒，却拔地而起，让$N落空。\n",
	"可是$n趴了个洞，钻了进去。\n",
	});

int valid_enable(string usage) 
{ 
	return (usage == "dodge"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("你的体力太差了，不能练雪遁。\n");
	me->receive_damage("qi", 30);
	return 1;
}

