// mujianping.c

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("沐剑屏", ({"mu jianping", "mu" }));
        set("title",HIY"神龙教"HIR"赤龙使"NOR"座下弟子");
        set("long",@LONG
她是沐王府小郡主，流落江湖成了神龙教赤龙门女弟子，长得十分娇羞秀
美。
LONG
);
        set("gender", "男性");
        set("attitude", "peaceful");

        set("age", 10+random(10));
        set("shen_type", -1);
        set("str", 25+random(10));
        set("dex", 25+random(10));
        set("max_qi", 200);
        set("max_jing", 150);
        set("neili", 200);
        set("max_neili", 200);
        set("jiaji", 5+random(5));
        set("combat_exp", 20000+random(10000));

        set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);
        set_skill("sword", 60);
        set_skill("shedao-qigong", 30);
        map_skill("sword","shedao-qigong");

        setup();
        carry_object("/d/shenlong/obj/xionghuang")->wield();
        carry_object("/clone/weapon/duanjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver",5);
}

void init()
{
        object ob;

        if( interactive(ob = this_player()) && !is_fighting()
        && living(this_object())) {
                remove_call_out("greeting");
                call_out("greeting", 10, ob);
        }
}
void greeting(object ob)
{
        object obj;

        if( !ob || environment(ob) != environment() ) return;
        if(objectp(obj = present("usedgao",ob))){
                set("combat_exp",query("combat_exp")- 50000);
                set("add_exp",1);
        }
}
