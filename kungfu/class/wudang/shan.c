// shan.c 张翠山

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("张翠山", ({ "zhang cuishan", "zhang" }));
        set("nickname", "武当五侠");
        set("long",@LONG
他就是张三丰的最聪明的弟子、武当七侠之五的张翠山。身穿一件干干净
净的青布长衫。他不过二十出头年纪，潇洒英俊，一副白马王子派头。
LONG
);
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("class", "scholar");
        set("shen_type", 1);
        set("str", 28);
        set("int", 30);
        set("con", 28);
        set("dex", 28);
        set("per", 28);

        set("jing",3000);
        set("max_jing", 3000);
        set("neili",4500);
        set("max_neili",4500);
        set("jingli", 1000);
        set("max_jingli",1000);
        set("jiali",225);
        set("combat_exp",2700000);
        set("score", 60000);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.lian" :),
        }) );
        set_skill("force", 300);
        set_skill("taiji-shengong", 300);
        set_skill("dodge", 300);
        set_skill("tiyunzong", 300);
        set_skill("unarmed", 300);
        set_skill("taiji-quan", 300);
        set_skill("parry", 300);
        set_skill("sword", 300);
        set_skill("liangyi-jian", 300);
        set_skill("taiji-jian", 300);
        set_skill("literate", 300);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry","liangyi-jian");
        map_skill("sword","liangyi-jian");
        set("chat_chance",5);
        set("chat_msg", ({
                "张翠山恶狠狠地说道：没有两把刷子，我敢来解剑岩？",
        }));
        create_family("武当派", 2, "弟子");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/bluecloth")->wear();
}
void init()
{
        object ob;
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",1,ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if ((int)ob->query("shen") < 0){
                say(CYN"\n\n张翠山脸现怒容：“邪魔外道，吃了豹子胆了，敢强闯武当！”\n\n");
                message_vision("张翠山居高临下，起手一掌，$N只得硬接，身子晃了一下。\n",ob);
                message_vision("对方右手长剑随即递出，$N无法招架，退了一步。\n\n\n"NOR,ob);
                ob->receive_damage("jing",50,this_object());
                ob->move("/d/wudang/slxl2");
        }
}
void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(ob) +"你对我武当派尽了多少心力，有几分忠心呢？");
                return;
        }
        if (ob->query_int() < 30)
        {
                command("say 你的资质将来到不了铁划银钩的境界，收你也是白搭。");
                return;
        }
        if ((int)ob->query("shen") < 10000) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +"是否还做得不够？");
                return;
        }
        if (ob->query_skill("taiji-shengong",1) < 200)
        {
                command("say 武当派以太极神功为修练武功基础，看来你的太极神功火候还不够吧？");
                return;
        }
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
}
