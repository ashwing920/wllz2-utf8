// tmdafa.c 天魔大法

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int i = (int)me->query_skill("tianmo-dafa", 1);
        int t = 1, j;

        if( i <= 100)
                for (j = 1; j < i / 10; j++) t*= 2;

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候不足，不能学天魔大法。\n");

        if(i<=100){
                if (i > 10 && -(int)me->query("shen") < t * 100)
                        return notify_fail("学天魔大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
        }
        else
        {
                if (-(int)me->query("shen") < (51200 + (i - 100) * 1000))
                        return notify_fail("学天魔大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
        }
        if ( me->query_skill("hunyuan-yiqi",1)
        || me->query_skill("huntian-qigong",1)
        || me->query_skill("taiji-shengong",1)
        || me->query_skill("douzhanxingyi",1)
        || me->query_skill("xuantian-force",1))
                return notify_fail("你不先散了别派内功，怎能学天魔大法？！\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("天魔大法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"tianmo-dafa/" + func;
}
