// luoying-xinfa.c 落英心法

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("落英心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return SKILL_D("luoying-xinfa/") + func;
}