// hamagong.c 蛤蟆功

#include <ansi.h>

inherit FORCE;

mapping *action = ({
([      "action": "$N忽而倒竖，一手撑地，身子横挺，只以一掌向$n的$l拍出",
	"dodge": 10,
	"force": 200,
	"lvl" : 0,
	"damage_type": "瘀伤"
]),
([      "action": "$N双手在地上一撑，身子忽地拔起，一跃三尺，落在$n的面前，单掌向$p直劈而下",
	"weapon" : "掌缘",
	"dodge": 15,
	"force": 230,
	"damage" : 20,
	"lvl" : 0,
	"damage_type": "割伤"
]),
([      "action": "$N突然伸手在自己脸上猛抓一把，又反足在自己肾上狠踢一脚，一掌击出，中途方向必变，实不知将打何处",
	"dodge": 5,
	"force": 350,
	"lvl" : 20,
	"damage_type": "瘀伤"
]),
([      "action": "突然之间，$N俯身疾攻，上盘全然不守，微微侧头，一口唾沫往$n$l吐去",
	"weapon" : "唾液",
	"dodge": 10,
	"force": 290,
	"damage" : 40,
	"lvl" : 50,
	"damage_type": "刺伤"
]),
([      "action": "$N丝毫不动声色，双腿微曲，右掌平伸，左掌缓缓运起蛤蟆功的劲力，呼的一声推向$n",
	"dodge": 5,
	"force": 380,
	"lvl" : 80,
	"damage" : 90,
	"damage_type": "瘀伤"
]),
([      "action": "$N默念口诀运气经脉，只觉愈转愈是顺遂，当下一个翻身跃起，咕的一声叫喊，双掌对着$n拍出",
	"dodge": 1,
	"force": 350,
	"lvl" : 110,
	"damage" : 150,
	"damage_type": "瘀伤"
]),
([      "action": "但见$N双腿微曲，双掌会收，然后向$n一上一下，一放一收，斗然击出",
	"dodge": 10,
	"force": 330,
	"lvl" : 140,
	"damage" : 200,
	"damage_type": "瘀伤"
]),
([  "action": "$N闭眼逼住呼吸，过了片刻，猛跃而起，眼睛也不及睁开，双掌便向$n的方向推了出去",
	"dodge": 0,
	"force": 450,
	"lvl" : 170,
	"damage" : 280,
	"damage_type": "内伤"
]),
([  "action": "$N脚步摇摇幌幌的看上去马上就会跌倒，忽然双腿一弯、一登，口中阁的一声叫喝，手掌向$n猛然推出",
	"dodge": 5,
	"force": 440,
	"lvl" : 199,
	"damage" : 400,
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) {

	return usage == "force" || usage=="strike" || usage =="parry" || usage=="unarmed";
}

int valid_learn(object me)
{
	int i = (int)me->query_skill("hamagong", 1);
	int t = 1, j;

	if( i <= 100)
		for (j = 1; j < i / 10; j++)
			t*= 2;

	if ( me->query("gender") == "无性" && i > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的蛤蟆功。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学蛤蟆功。\n");

	if(i<=100){
		if (i > 10 && -(int)me->query("shen") < t * 100)
			return notify_fail("学蛤蟆功，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
	}
	else
	{
		if (-(int)me->query("shen") < (51200 + (i - 100) * 1000))
			return notify_fail("学蛤蟆功，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
	}

	if ( me->query_skill("bibo-shengong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("biyun-xinfa",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("xixing-force",1)
	|| me->query_skill("xuehai-mogong",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("zixia-shengong",1)
	|| me->query_skill("douzhuanxingyi",1)
	|| me->query_skill("xuantian-force",1))
		return notify_fail("你不先散了别派内功，怎能学蛤蟆功？！\n");
	return 1;
}
string query_skill_name(int level)
{
	int i = sizeof(action);

	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me)
{
	int i, level;

	level   = (int) me->query_skill("hamagong",1);
	if (random(me->query_str()) > 35 &&
	    random(level) > 120 &&
	    me->query("max_neili") > 3000 &&
	    me->query("neili") > 1300 ) {
		me->add("neili", -50);
		return ([
			"action": HIC "$N蹲低身子，两眼微闭，口中咕咕咕的叫了三声，双掌向$n缓缓推出！激得灰泥弥漫，尘土飞扬" NOR,
			"dodge" : 10,
			"force": 750,
			"damage":600,
			"damage_type": "瘀伤"
		]);
	}

	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	return notify_fail("蛤蟆功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"hamagong/" + func;
}
string perform_action_file(string action)
{
	return __DIR__"hamagong/" + action;
}
mapping exercise_msg(object me)
{
	return ([
		"status_msg" : "双手撑地，倒挂而立，体态十分轻盈。",
		"start_my_msg" : "你向前卧倒，撑地而起，倒挂而立，一股内劲倒流而至。\n",
		"start_other_msg" : me->name() + "双手撑地，倒挂而立，体态十分轻盈。。\n",
		"end_my_msg" : "你将真气引回丹田，双手一推，站了起来。\n",
		"end_other_msg" : me->name() + "将真气引回丹田，双手一推，站了起来。\n",
		"halt_msg": me->name() +"猛然将真气急急收回，双手就地一推，跳了起来。\n",
	]);
}
