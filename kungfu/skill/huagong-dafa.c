// huagong-dafa.c 化功大法

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int i = (int)me->query_skill("huagong-dafa", 1);
        int t = 1, j;

        if(i <= 100)
                for (j = 1; j < i / 10; j++)
                        t*= 2;

        if ( me->query("gender") == "无性" && i > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的化功大法。\n");

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候不足，不能学化功大法。\n");

        if(i<=100)
        {
                if (i > 10 && -(int)me->query("shen") < t * 100) 
                        return notify_fail("学化功大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
        }
        else
        {
                if (-(int)me->query("shen") < (51200 + (i - 100) * 1000)) 
                        return notify_fail("学化功大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
        }

        if ( me->query_skill("bibo-shengong",1)
        || me->query_skill("beiming-shengong",1)
        || me->query_skill("bahuang-gong",1)
        || me->query_skill("biyun-xinfa",1)
        || me->query_skill("hamagong",1)
        || me->query_skill("huntian-qigong",1)
        || me->query_skill("hunyuan-yiqi",1)
        || me->query_skill("jiuyang-shengong",1)
        || me->query_skill("kurong-changong",1)
        || me->query_skill("linji-zhuang",1)
        || me->query_skill("longxiang",1)
        || me->query_skill("taiji-shengong",1)
        || me->query_skill("xiaowuxiang",1)
        || me->query_skill("xiantian-qigong",1)
        || me->query_skill("xixing-force",1)
        || me->query_skill("xuehai-mogong",1)
        || me->query_skill("xuantian-force",1)
        || me->query_skill("yijinjing",1)
        || me->query_skill("yunlong-shengong",1)
        || me->query_skill("yunv-xinfa",1)
        || me->query_skill("zixia-shengong",1)
        || me->query_skill("douzhuanxingyi",1))
                return notify_fail("你不先散了别派内功，怎能学化功大法？！\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("化功大法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"huagong-dafa/" + func;
}

mapping exercise_msg(object me)
{
        return ([
                "status_msg" : "正坐在地上修练内息，身体被一股青烟环绕着。",
                "start_my_msg" : "你气运丹田，将体内毒素慢慢逼出，控制着它环绕你缓缓飘动。你感觉到内劲开始有所加强了。\n",
                "start_other_msg" : me->name()+"盘膝坐下运功，身体渐渐被一股青烟所包围。\n",
                "halt_msg" : "$N双眼一睁，眼中射出一道精光，接着阴阴一笑，站了起来。\n",
                "end_my_msg" : "你感觉毒素越转越快，就快要脱离你的控制了！你连忙收回毒素和内息，冷笑一声站了起来。\n",
                "end_other_msg" : me->name()+"阴阴一声冷笑，呼出一口青烟，站起身来藐视地扫了在场的人一眼。\n"
        ]);
}
