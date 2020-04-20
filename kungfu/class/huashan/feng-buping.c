// feng-buping.c  封不平

inherit NPC;
inherit F_MASTER;

#include <ansi.h>

void create()
{
        set_name("封不平", ({ "feng buping", "feng" }) );
        set("nickname", YEL"狂风快剑"NOR);
        set("gender", "男性");
        set("class", "swordsman");
        set("title", "华山剑宗第十三代弟子");
        set("age", 45);
        set("long",@LONG
封不平是华山剑宗第一高手，满脸戾气一张黄焦焦的面皮。
LONG
);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("jing",10000);
        set("max_jing",10000);
        set("neili", 12000);
        set("max_neili",12000);
        set("jiali",600);

        set("combat_exp",51200000);
        set("shen_type", 1);
        set("apprentice_available", 3);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
        }) );

        set_skill("unarmed", 800);
        set_skill("sword", 800);
        set_skill("force", 800);
        set_skill("parry", 800);
        set_skill("dodge", 800);
        set_skill("literate", 800);
        set_skill("huashan-sword", 800);
        set_skill("kuangfeng-jian", 800);
        set_skill("huashan-neigong", 800);
        set_skill("huashan-ken", 800);
        set_skill("huashan-zhangfa", 800);
        set_skill("huashan-shenfa", 800);

        map_skill("sword", "kuangfeng-jian");
        map_skill("parry", "kuangfeng-jian");
        map_skill("force", "huashan-neigong");
        map_skill("unarmed", "huashan-zhangfa");
        map_skill("dodge", "huashan-shenfa");

        create_family("华山剑派", 13, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit",0,ob);
        } else {
                command("say 老夫今天已经收了三个弟子，不想再收徒了。");
        }
}

void do_recruit(object ob)
{
        if((int)ob->query("int") < 25 ){
                command("say 我华山剑派以剑法为主，依我看"+RANK_D->query_respect(ob)+"不适合于学剑法。");
                return;
        }
        if((int)ob->query_skill("sword",1) < 300) {
                command("say 我华山剑派以剑法为主，依我看"+ RANK_D->query_respect(ob)+"的剑法还不到家啊！");
                return;
        }
        if((int)ob->query_skill("huashan-sword",1) < 300) {
                command("say 狂风剑法是由华山剑法演练，依我看"+ RANK_D->query_respect(ob)+"的华山剑法还不到家啊！");
                return;
        }
                
                else {
                command("say 好，我就收下你吧！");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("title", "华山剑宗第十四代弟子");
        ob->set("class", "swordsman");
        add("apprentice_availavble", -1);
}
void reset()
{
        set("apprentice_available", 3);
}

