// bibo-shengong.c 碧波神功

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("bibo-shengong", 1);

        if( me->query_skill("force",1) < 10 )
                return notify_fail("你连基本内功都不会，更别说这门高深的内功心法了。\n");

        if ( me->query("gender") == "无性" && lvl > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的碧波神功。\n");

        if ( me->query_skill("beiming-shengong",1)
        || me->query_skill("bahuang-gong",1)
        || me->query_skill("biyun-xinfa",1)
        || me->query_skill("hamagong",1)
        || me->query_skill("huagong-dafa",1)
        || me->query_skill("huntian-qigong",1)
        || me->query_skill("hunyuan-yiqi",1)
        || me->query_skill("longxiang",1)
        || me->query_skill("jiuyang-shengong",1)
        || me->query_skill("taiji-shengong",1)
        || me->query_skill("kurong-changong",1)
        || me->query_skill("linji-zhuang",1)
        || me->query_skill("xiantian-qigong",1)
        || me->query_skill("xuehai-mogong",1)
        || me->query_skill("yijinjing",1)
        || me->query_skill("xiaowuxiang",1)
        || me->query_skill("xixing-force",1)
        || me->query_skill("yunlong-shengong",1)
        || me->query_skill("yunv-xinfa",1)
        || me->query_skill("zixia-shengong",1)
        || me->query_skill("douzhuanxingyi",1)
        || me->query_skill("xuantian-force",1))
                return notify_fail("你不先散了别派内功，怎能学碧波神功？！\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("碧波神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"bibo-shengong/" + func;
}
mapping exercise_msg(object me)
{
	return ([
		"status_msg" : "面容肃穆，静坐如渊岳，沐轻风而不惊。",
		"start_my_msg" : "你盘腿坐下，双目微闭，双手掌心相向成虚握太极，天人合一，练气入虚。\n",
		"start_other_msg" : me->name() + "盘腿坐下，双目微闭，双手掌心相向成虚握太极。轻风吹过，" + me->name() + "身上的衣袍竟然不为所动。\n",
		"end_my_msg" : "你将内息又运了一个小周天，缓缓导入丹田，双臂一震，站了起来。\n",
		"end_other_msg" : me->name() + "的脸上红光乍现，又立刻隐去。随即双臂一震，站了起来。\n"
	]);
}
