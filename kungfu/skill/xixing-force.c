// xixing-force.c
// 吸星大法

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("xixing-force", 1);
	int t = 1, j;

	if( i <= 100)
		for (j = 1; j < i / 10; j++) t*= 2;

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学吸星大法。\n");

	if((int)me->query_skill("force",1) < (int)me->query_skill("xixing-force",1))
		return notify_fail("你的基本内功修为太差，无法再修炼更高一层的吸星大法了。\n");

	if(i<=100){
		if (i > 10 && -(int)me->query("shen") < t * 100)
			return notify_fail("学吸星大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
	}
	else
	{
		if (-(int)me->query("shen") < (51200 + (i - 100) * 1000))
			return notify_fail("学吸星大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
	}

	if ( me->query_skill("bibo-shengong",1)
	|| me->query_skill("biyun-xinfa",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("xuehai-mogong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("zixia-shengong",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("douzhuanxingyi",1)
	|| me->query_skill("xuantian-force",1))
		return notify_fail("你不先散了别派内功，怎能学吸星大法？！\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("吸星大法只能用学的，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
	return __DIR__"xixing-force/" + func;
}
