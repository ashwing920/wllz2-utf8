// douzhuan-force.c - 斗转星移

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) 
{ 
	mapping skl;
	string *sname;
	int i, nf, nh;
	nf = (int)me->query_skill("shenyuan-gong", 1);
	nh = (int)me->query_skill("douzhuanxingyi", 1);

	if ( me->query("gender") == "无性" && nh > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的玄天无极内功。\n");

	if( (string)me->query("family/family_name") != "慕容世家")
		return notify_fail("只有慕容世家的弟子才可以学习斗转星移。\n");
	if( (int)me->query_skill("force") < 10 )
        	return notify_fail("你的基本内功火候不够，无法研习高深的内功。\n");
	if( nf < nh )
		return notify_fail("你必须以修炼神元功来为斗转星移做基础。\n");
	
	skl = me->query_skills();
	sname  = keys(skl);
	for (i=0;i<sizeof(skl);i++){
		if (sname[i]=="douzhuanxingyi") continue;
		if (sname[i]=="shenyuan-gong") continue;
			if( SKILL_D(sname[i])->valid_enable("force") )
		return notify_fail("你不先散了别派内功，怎能学斗转星移呢？！\n");
	
	return 1; 
	}
}

int practice_skill(object me)
{
        return notify_fail("斗转星移只能学习（learn），或是从运用（exert）中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"douzhuanxingyi/" + func;
}
