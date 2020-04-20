#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("杨过", ({ "yang guo", "yang", "master" }));
        set("long",@LONG
他是新近堀起江湖的超一流高手，据传他是百年以前剑圣“独孤求败”的
唯一传人。他手中一柄玄铁剑无坚不摧，近年更因思念心上人小龙女而创
出一套“黯然销魂掌”，得身旁一头神雕相助，出入百万蒙古军中如履平
地。他身材高大，却只有独臂，两缕早白的头发从两侧垂落肩膀。
LONG
);

        create_family("古墓新派",3,"弟子");
        set("nickname",YEL"神雕大侠"NOR);
        set("rank_info/respect", "大侠");
        set("gender", "男性" );
        set("age", 30);

        set("str", 30);
        set("cps", 30);
        set("per", 30);
        set("int", 30);
        set("con", 30);
        set("kar", 30);

        set("combat_exp",51200000);
        set("shen_type",1);
        set("max_neili",12000);
        set("neili",12000);
        set("jiali",600);
        set("jing",10000);
        set("max_jing",10000);
        
        set_skill("force",    800);     set_skill("xiantian-qigong", 800);
        set_skill("sword",    800);     set_skill("xuantie-sword", 800);
        set_skill("unarmed",  800);     set_skill("xiaohun-zhang", 800);
        set_skill("parry",    800);     set_skill("quanzhen-jian",800);
        set_skill("dodge",    800);
        set_skill("literate", 800);
        set_skill("perception",800);
        set_skill("yingfeng-steps",800);
        set_skill("strike",800);
        map_skill("force",      "xiantian-qigong");
        map_skill("sword",      "xuantie-sword");
        map_skill("unarmed",    "xiaohun-zhang");
        map_skill("parry",      "quanzhen-jian");
        map_skill("dodge",      "yingfeng-steps");
        map_skill("strike",     "xiaohun-zhang");

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action,"sword.xuan" :),
                (: perform_action,"parry.ding" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: exert_function, "bidu" :),
                (: exert_function, "regenerate" :),
                (: perform_action,"unarmed.xiaohun":),
        }) );
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/d/gumu/npc/obj/xuantiejian")->wield();
        carry_object("/d/gumu/npc/obj/junzijian");
}
void attempt_apprentice(object ob)
{

        if( ((string)ob->query("gender") != "男性")) {
                command("say 这位" + RANK_D->query_respect(ob) + "请回去吧，我不收女弟子的。");
                return;
        } 

        if((int)ob->query_int() < 35) {
                command("say 依我看" + RANK_D->query_respect(ob) + "的资质还不够高？");
                return;
        } 

        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
        command("recruit " + ob->query("id") );
        ob->set("class","swordsman");
}
