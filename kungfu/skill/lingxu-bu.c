// lingxu-bu 凌虚步

inherit SKILL;

string *dodge_msg = ({
	"只见$n左一步，右一步，轻而易举的躲过$N这一招。\n",
	"但是$n身形一动，从不可思义的角度转过身来，避开了$N的攻击。\n",
	"然而$n却不退反进，脚下步点变幻莫测，反使$N的攻势全部落空。\n"
	"但是$n身形飘忽，忽前忽后，忽左忽右，让$N无法下手。\n",
	"可是$n身随意转，脚步微变，人竟已在三丈之外，闪过了这一招。\n",
	
	});

mapping *action = ({
([	"action" : "$n一式「雪地莲花」，身子掣忽一转，$N只觉的眼前一花，失去了目标。\n",
	"dodge"  : 40
]),
([	"action" : "$n一式「一狐冲天」，双脚点地，身子突然拔高了丈许，缓缓飘落在$N身后。\n",
	"dodge"  : 60
]),
([	"action" : "$n一式「移行幻影」，身行一晃，顿时无数条身影一下子出现在$N的面前。\n",
	"dodge"  : 80
]),
([	"action" : "$n一式「狡兔三窟」，飘然向后一退，躲开$N的凌厉攻势。\n",
	"dodge"  : 100
]),
([	"action" : "$n一式「烟雨飘渺」，身体急转，化为一道白光，虚幻不定的出现在$N的周围。\n",
	"dodge"  : 120
]),
});


int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("你的体力太差了，不能练凌虚步。\n");
	me->receive_damage("qi", 30);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"lingxu-bu/" + action;
}

