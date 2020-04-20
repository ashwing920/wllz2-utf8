// huntian-qigong.c

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("huntian-qigong", 1);

	if ( me->query("gender") == "无性" && i > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的混天气功。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够，还不能学习混天气功。\n");


	if( me->query_skill("bibo-shengong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("biyun-xinfa",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("zixia-shengong",1)
	|| me->query_skill("douzhuanxingyi",1)
	|| me->query_skill("xuantian-force",1)
	|| me->query_skill("xixing-force",1)
	|| me->query_skill("xuehai-mogong",1)
	|| me->query_skill("yijinjing",1))
		return notify_fail("你不先散了别派内功，怎能学混天气功？！\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("混天气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"huntian-qigong/" + func;
}
mapping exercise_msg(object me)
{
	return ([
		"status_msg" : "面带神光，衣袍飞舞。",
		"start_my_msg" : "你随意坐下，双手平放在双膝，默念口诀，开始运起独门心法。\n",
		"start_other_msg" : me->name()+"随意在那里坐下，双手平放在双膝，嘴唇微微颤动，身上的衣袍开始鼓动起来。\n",
		"halt_msg" : "$N面色一沉，迅速收气，站了起来。\n",
		"end_my_msg" : "你吸气入丹田，真气运转渐缓，慢慢收功，双手抬起，站了起来。\n",
		"end_other_msg" : "只见"+me->name()+"双手抬起，站了起来，衣袍慢慢垂了下来。\n"
	]);
}
