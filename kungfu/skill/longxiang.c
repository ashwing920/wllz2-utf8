// longxiang.c 龙象般若功

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int i = (int)me->query_skill("longxiang", 1);
        int t = 1, j;

        if( i <= 100)
        for (j = 1; j < i / 10; j++) t*= 2;

        if (((string)me->query("class") != "lama") && i > 29)
                return notify_fail("你不是僧人，学不了高深的龙象般若功。\n");

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候不足，不能学龙象般若功。\n");

        if ( me->query("gender") == "无性" && i > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的龙象般若功。\n");

        if(i<=100){
                if (i > 10 && -(int)me->query("shen") < t * 100)
                        return notify_fail("要学龙象般若功，你的表现还不够吧！ \n");
        }
        else
        {
                if (-(int)me->query("shen") < (51200 + (i - 100) * 1000))
                        return notify_fail("要学龙象般若功，你的表现还不够吧！ \n");
        }
        if( me->query_skill("bahuang-gong",1)
        || me->query_skill("bibo-shengong",1)
        || me->query_skill("beiming-shengong",1)
        || me->query_skill("biyun-xinfa",1)
        || me->query_skill("hamagong",1)
        || me->query_skill("huagong-dafa",1)
        || me->query_skill("huntian-qigong",1)
        || me->query_skill("hunyuan-yiqi",1)
        || me->query_skill("jiuyang-shengong",1)
        || me->query_skill("kurong-changong",1)
        || me->query_skill("linji-zhuang",1)
        || me->query_skill("taiji-shengong",1)
        || me->query_skill("xiantian-qigong",1)
        || me->query_skill("xixing-force",1)
        || me->query_skill("xuehai-mogong",1)
        || me->query_skill("yijinjing",1)
        || me->query_skill("yunv-xinfa",1)
        || me->query_skill("yunlong-shengong",1)
        || me->query_skill("zixia-shengong",1)
        || me->query_skill("douzhuanxingyi",1)
        || me->query_skill("xuantian-force",1))
                return notify_fail("你不先散了别派内功，怎能学龙象般若功。\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("龙象般若功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"longxiang/" + func;
}
mapping exercise_msg(object me)
{
        return ([
                "status_msg" : "神色俨然，凝神闭目。",
                "start_my_msg" : YEL"你盘膝入定，凝聚体内真气，摧动内息将腹中一丝丝游气慢慢增厚。\n"NOR,
                "start_other_msg" :YEL + me->name()+"盘膝坐定，一掌向上推出，一手垂于丹田，面目极是诡异，让人心桤摇动。\n"NOR,
                "halt_msg" : YEL "$N突然双手向胸前一合，压住腹中内息，凌空越起。\n"NOR,
                "end_my_msg" : YEL "你一周天行将下来，顿时浑身发暖，感到腹中内劲又增加一分。\n"NOR,
                "end_other_msg" : YEL "只见"+me->name()+"头顶白气渐散，双掌向胸前一合，起身站了起来。\n"NOR
        ]);
}
