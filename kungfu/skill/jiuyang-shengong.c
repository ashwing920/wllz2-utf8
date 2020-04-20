// jiuyang-shengong.c 九阳神功

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("jiuyang-shengong", 1);

	if ( me->query("family/family_name") != "明教"
	   && me->query("family/family_name") != "少林派" )
		return notify_fail("九阳神功博大精深, 非少林与明教弟子不传！\n");

	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的九阳神功。\n");

	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候还不够，无法领会九阳神功。\n");

	if(me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
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
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("zixia-shengong",1)
	|| me->query_skill("douzhuanxingyi",1)
	|| me->query_skill("xuantian-force",1)
	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("huashen-neigong",1))
		return notify_fail("你不先散了别派内功，怎能学九阳神功？！\n");

	return 1;
}

string exert_function_file(string func)
{
	return __DIR__"jiuyang-shengong/" + func;
}
