// yijinjing.c 少林 易筋经神功

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}

int valid_learn(object me)
{
        int nb, nf, oh, nh, ns;
        nb = (int)me->query_skill("buddhism", 1);
        nf = (int)me->query_skill("force", 1);
        oh = (int)me->query_skill("hunyuan-yiqi", 1);
        nh = (int)me->query_skill("yijinjing", 1);
        ns = (int)me->query("guilty");

        if ( oh < 100 )
                return notify_fail("你的混元一气太低，无法学习易筋经神功！\n");
        if ( me->query("marry") )
                return notify_fail("你已经破了色戒，无法再学习易筋经神功！\n");

        if ( me->query("gender") != "男性" )
                return notify_fail("你非童男之体，不能练习易筋经神功。\n");

        if ( nb < 100 && nb <= nh )
                return notify_fail("你的禅宗心法修为不够，无法领会更高深的易筋经神功。\n");

        if ( nf < 10)
                return notify_fail("你的基本内功火候还不够，无法领会易筋经神功。\n");

        if ( ns > 0 ) 
                return notify_fail("你屡犯僧家数戒，无法领会更高深的易筋经神功。\n");

        if (me->query_skill("bahuang-gong",1)
        || me->query_skill("beiming-shengong",1)
        || me->query_skill("bibo-shengong",1)
        || me->query_skill("biyun-xinfa",1)
        || me->query_skill("hamagong",1)
        || me->query_skill("huagong-dafa",1)
        || me->query_skill("huntian-qigong",1)
        || me->query_skill("jiuyang-shengong",1)
        || me->query_skill("kuihua-xinfa",1)
        || me->query_skill("kurong-changong",1)
        || me->query_skill("xiantian-qigong",1)
        || me->query_skill("xiaowuxiang",1)
        || me->query_skill("linji-zhuang",1)
        || me->query_skill("longxiang",1)
        || me->query_skill("taiji-shengong",1)
        || me->query_skill("yunlong-shengong",1)
        || me->query_skill("yunv-xinfa",1)
        || me->query_skill("zixia-shengong",1)
        || me->query_skill("douzhuanxingyi",1)
        || me->query_skill("xixing-force",1)
        || me->query_skill("xuantian-force")
        || me->query_skill("shenlong-xinfa",1))
                return notify_fail("你不先散了别派内功，怎能学易筋经神功？！\n");

        return 1;
}


int practice_skill(object me)
{
        return notify_fail("易筋经神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"yijinjing/" + func;
}
mapping exercise_msg(object me)
{
        return ([
                "status_msg" : "脸上红光隐现，气象庄严。",
                "start_my_msg" : "你五心向天，排除一切杂念，内息顺经脉缓缓流动。\n",
                "start_other_msg" : me->name()+"五心向天，一会工夫，从口鼻处缓缓吐出白气，白气越吐越浓，渐渐笼罩了全身。\n",
                "halt_msg" : "$N长出一口气，将内息急速退了回去，站了起来。\n",
                "end_my_msg" : "你将内息走了个小周天，流回丹田，收功站了起来。\n",
                "end_other_msg" : "只见笼罩"+me->name()+"的白气渐渐消散，又从口鼻处吸了回去。\n",
                "heal_msg" : HIY"$N双手合什，盘膝而坐，口中念起“往生咒”，开始运功疗伤。\n"NOR,
                "heal_finish_msg" : HIY"$N缓缓站起，只觉全身说不出的舒服畅快，便道：“善哉！善哉！本门筋经当真是天下绝学！”\n"NOR,
                "heal_unfinish_msg" : "$N吐出瘀血，缓缓站起，但脸色苍白，看来还有伤在身。\n",
                "heal_halt_msg" : "$N一声：“阿弥陀佛”双袖挥动，压下内息，站起身来。\n",
        ]);
}
