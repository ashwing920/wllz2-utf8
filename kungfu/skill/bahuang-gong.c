// bahuang-gong.c 八荒六合唯我独尊功

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("bahuang-gong", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t *= 2;

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

	   if ( me->query_skill("bibo-shengong",1)	 
		|| me->query_skill("hamagong",1)
		|| me->query_skill("huagong-dafa",1)
		|| me->query_skill("huntian-qigong",1)
		|| me->query_skill("hunyuan-yiqi",1)
		|| me->query_skill("longxiang",1)
		|| me->query_skill("jiuyang-shengong",1)
		|| me->query_skill("taiji-shengong",1)
		|| me->query_skill("xiaowuxiang",1)
		|| me->query_skill("yunlong-shengong",1)
		|| me->query_skill("zixia-shengong",1)
		|| me->query_skill("douzhuanxingyi",1)
		|| me->query_skill("xuantian-force",1)
		|| me->query_skill("xixing-force",1)
		|| me->query_skill("biyun-xinfa",1)
		|| me->query_skill("yijinjing",1))
		return notify_fail("你不先散了别派内功，怎能学八荒六合唯我独尊功？！\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("八荒六合唯我独尊功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"bahuang-gong/" + func;
}
mapping exercise_msg(object me)
{
	return ([
		"status_msg" : "面容肃穆，安然静坐，真气游荡周身。",
		"start_my_msg" : MAG"你盘膝而坐，左手指天，右手指地，默运八荒六合惟我独尊功，引一口丹田之气游走全身。\n"NOR,
		"start_other_msg" : MAG+ me->name() + "盘膝而坐，左手指天，右手指地，默运八荒六合惟我独尊功，引一口丹田之气游走全身。\n"NOR,
		"end_my_msg" : MAG"你将真气引回丹田，金色烟气顿消，缓缓的站了起来。\n"NOR,
		"end_other_msg" : MAG + me->name() + "将真气引回丹田，金色烟气顿消，缓缓的站了起来。\n"NOR,
		"halt_msg": MAG + me->name() +"哼了一声，将运行的真气压下，站了起来。\n"NOR,
	]);
}
