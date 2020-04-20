// huashan-neigong.c 华山内功

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_public(object me)
{
	mapping skl = me->query_skills();
	string *sk;
	int i;
	string skl_name = explode(__FILE__, "/")[<1][0..<3];

	if (!mapp(skl)) return 1;
	sk = keys(skl);
	i = sizeof(sk);
	while (i--) {
		if (sk[i] != skl_name && SKILL_D(sk[i])->valid_enable("force")
		&& sk[i] != "zixia-shengong")
		return notify_fail("你不散掉"+to_chinese(sk[i]) +"，如何能修习"+to_chinese(skl_name)+"。\n");
	}
	return 1;
}

int valid_learn(object me)
{
	if (me->query_skill("force", 1) > 9)
		return valid_public(me);
	return notify_fail("你的基本内功还需要进一步提高。\n");
}

int practice_skill(object me)
{
	return notify_fail("华山气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"huashan-neigong/" + func;
}
