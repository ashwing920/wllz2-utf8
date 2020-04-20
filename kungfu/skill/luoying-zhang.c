// luoying.c

inherit SKILL;

mapping *action = ({
([      "action" : "$N纵身向前，掌势一发即收，双掌连晃，已抢到$n的面前，使出「落英缤纷」，虚虚实实，若有若无地袭向$n",
	"lvl" : 0,
	"skill_name" : "落英缤纷",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N左足一点，跃起丈余，在半空连转两个圈子，凌空挥掌，掌做剑形，\n一招「江城飞花」，向$n当头击下",
	"lvl" : 7,
	"skill_name" : "江城飞花",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N左足在前，右足在后，单臂画了个弧线，正是「雨打桃花」，劈头盖脸地向$n按去",
	"lvl" : 15,
	"skill_name" : "雨打桃花",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N身形一转，已经欺到$n近前，立掌如剑，单手横劈，飕飕风响，\n一招「雨急风狂」划向$n的$l",
	"lvl" : 28,
	"skill_name" : "雨急风狂",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N身形连晃，倏忽间已围着$n转了几个圈子，掌影飘飘，正是一招「无边落木」，\n从四面八方向$n袭去",
	"lvl" : 45,
	"skill_name" : "无边落木",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N长笑一声，踏上一步，双掌连击，虚招多而实招少，霎时化作「满天花雨」，\n将$n的全身都笼罩在掌影之中",
	"lvl" : 60,
	"skill_name" : "满天花雨",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N暗暗运劲，力贯双臂，身子如剑般扑向$n，两掌一前一后，\n使出一招「断艳残红」，狠狠地按向$n的前胸",
	"lvl" : 80,
	"skill_name" : "断艳残红",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N双手平伸，向外掠出，一式「春云乍展」，指尖轻盈漂动，轻轻反点$n的$l",
	"damage_type" : "瘀伤",
	"lvl" : 100,
	"skill_name" : "春云乍展"
]),
([      "action" : "$N右手五指缓缓一收，一式「回风拂柳」，五指忽然遥遥拂向$n，$n只觉得五股疾风袭向自己五处大穴",
	"lvl" : 150,
	"damage_type" : "内伤",
	"skill_name" : "回风拂柳"
]),
([      "action" : "$N突然纵身跃入半空，一个轻巧转身，单掌劈落，一式「江城飞花」，拍向$n的头顶",
	"lvl" : 180,
	"damage_type" : "瘀伤",
	"skill_name" : "江城飞花"
]),
([      "action" : "$N突然跃起，双手连环，运掌如剑，势如疾风电闪，一式「雨急风狂」，攻向$n的全身",
	"lvl" : 200,
	"damage_type" : "瘀伤",
	"skill_name" : "雨急风狂"
]),
([      "action" : "$N左手挥起，掌心朝天，伸出右手并拢食指中指，捻个剑决，一式「星河在天」，直指$n的中盘",
	"lvl" : 250,
	"damage_type" : "瘀伤",
	"skill_name" : "星河在天"
]),
([      "action" : "$N突然抽身而退，接着一式「流华纷飞」，平身飞起，双掌向$n的后脑连拍数掌",
	"lvl" : 300,
	"damage_type" : "瘀伤",
	"skill_name" : "流华纷飞"
]),
([      "action" : "$N突然抽身跃起，左掌挟着劲风汹涌拍出，接着右掌自左掌后突地伸出，\n一式「彩云追月」抢在左掌前向$n的$l拍去",
	"lvl" : 350,
	"damage_type" : "瘀伤",
	"skill_name" : "彩云追月"
]),
([      "action" : "$N使一式「天如穹庐」，全身突然飞速旋转，双掌忽前忽后，猛地拍向$n的胸口",
	"lvl" : 400,
	"damage_type" : "瘀伤",
	"skill_name" : "天如穹庐"
]),
([      "action" : "$N前后一揉，一式「朝云横度」，化掌如剑，一股凌厉剑气袭向$n的下盘",
	"lvl" : 420,
	"damage_type" : "内伤",
	"skill_name" : "朝云横度"
]),
([      "action" : "$N使一式「白虹经天」，双掌舞出无数圈劲气，一环环向$n的$l斫去",
	"lvl" : 450,
	"damage_type" : "内伤",
	"skill_name" : "白虹经天"
]),
([      "action" : "$N双手食指和中指一和，一式「紫气东来」，一股强烈的气流涌向$n的全身",
	"lvl" : 460,
	"damage_type" : "内伤",
	"skill_name" : "紫气东来"
]),
([      "action" : "$N一式「落英漫天」，双掌在身前疾转，掌花飞舞，铺天盖地直指向$n。\n$n只见漫天掌花，眼花缭乱。",
	"lvl" : 500,
	"damage_type" : "瘀伤",
	"skill_name" : "落英漫天"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="xuanfeng-leg"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
	return notify_fail("练落英神剑掌必须空手。\n");
	if ((int)me->query("max_neili") < 100)
	return notify_fail("你的内力太弱，无法练落英神剑掌。\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
	mapping a_action;
	int i, level;
	level = (int)me->query_skill("luoying-zhang",1);
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
	a_action["weapon"] = random(2)?"剑掌":"掌风";
	a_action["damage_type"] = random(2)?"劈伤":"砍伤";
	return a_action;

}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 10)
	return notify_fail("你的内力不够了！休息一下再练吧。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"luoying-zhang/" + action;
}
