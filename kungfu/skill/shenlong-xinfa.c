// shenlong-xinfa.c 神龙心法

inherit FORCE;

void create() { seteuid(getuid()); }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 30)
                return notify_fail("你的基本内功火候还不够，无法领会神龙心法。\n");

        if(me->query_skill("douzhuanxingyi",1)
        || me->query_skill("xuantian-force",1)
        || me->query_skill("jiuyang-shengong",1)
        || me->query_skill("yijinjing",1))
                return notify_fail("你不先散了别派内功，怎能学神龙心法？！\n");

        return 1;
}
int practice_skill(object me)
{       
        return notify_fail("神龙心法只能靠学(learn)来提高。\n");
}

string exert_function_file(string func)
{
        return __DIR__"shenlong-xinfa/" + func;
}
