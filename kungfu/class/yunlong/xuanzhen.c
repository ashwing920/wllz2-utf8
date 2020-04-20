    // xuanzhen.c 玄贞道长

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_weiwang();
string ask_me();

void create()
{
        set_name("玄贞道长", ({ "xuan zhen", "xuan", "zhen" }));
        set("gender", "男性");
        set("title", HIR "天地会"HIG"青木堂"NOR"会众");
        set("long",@LONG
这位沉默寡言的道人，便是天地会青木堂护法。他是青木堂数一数二的好
手，一柄长剑使得出神入化。
LONG
);
        set("age", 55);
        set("class", "taoist");
        set("int", 30);
        
        set("jing",2000);
        set("max_jing",2000);
        set("neili",3000);
        set("max_neili",3000);
        set("jiali",150);
        set("shen_type",1);

        set("combat_exp", 800000);
        set("attitude", "friendly");

        set_skill("force", 200);
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("sword", 200);
        set_skill("whip", 200);
        set_skill("hand", 200);
        set_skill("claw", 200);
        set_skill("yunlong-shengong", 200);
        set_skill("yunlong-shenfa", 200);
        set_skill("yunlong-xinfa", 200);
        set_skill("yunlong-bian", 200);
        set_skill("yunlong-jian", 200);
        set_skill("yunlong-shou", 200);
        set_skill("yunlong-zhua", 200);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 50);

        map_skill("force", "yunlong-shengong");
        map_skill("dodge", "yunlong-shenfa");
        map_skill("parry", "yunlong-jian");
        map_skill("sword", "yunlong-jian");
        map_skill("hand", "yunlong-shou");
        map_skill("claw", "yunlong-zhua");
        map_skill("whip", "yunlong-bian");

        prepare_skill("hand", "yunlong-shou");
        prepare_skill("claw", "yunlong-zhua");
        create_family("云龙门",2, "弟子");
        set("book_count", 1);
        set("inquiry", ([
                "陈近南" :  "\n江湖威望值达到70就可以拜总舵主为师。\n",
                "天地会" :  "\n只要是英雄好汉，都可以入我天地会。\n",
                "入会" :  "\n只要入了我天地会，可以向会中各位好手学武功。\n",
                "反清复明" : "去药铺和棺材店仔细瞧瞧吧！\n",
                "威望" :  (: ask_weiwang :),
                "江湖威望" : (: ask_weiwang :),
                "云龙经" : (: ask_me :),
        ]) );
        set("chat_chance_combat", 50);  
        set("chat_msg_combat", ({
                (: command("smile") :),
                (: command("haha") :),
                (: command("chat 这位" + RANK_D->query_respect(this_player())+"，你我无冤无仇，何必如此？\n") :),
                (: command("unwield changjian") :),
                (: command("unwield changjian") :),
                (: command("unwield changjian") :),
                (: command("unwield changjian") :),
                (: command("unwield changjian") :),
                (: command("unwield changjian") :),
                (: command("unwield changjian") :),
                (: command("unwield changjian") :),
                (: command("wield changjian") :),
                (: command("wield changjian") :),
                (: command("wield changjian") :),
                (: command("wield changjian") :),
                (: command("wield changjian") :),
                (: command("wield changjian") :),
                (: command("wield bian") :),
                (: command("wield bian") :),
                (: command("wield bian") :),
                (: command("wield bian") :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: command("unwield bian") :),
                (: command("unwield bian") :),
                (: command("unwield bian") :),
                (: command("unwield bian") :),
        }));
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",3);
}

void init()
{
        object ob;
        if( interactive(ob=this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
int ask_weiwang()
{
        command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
        say("\n玄贞说道：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
        +"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
        say("玄贞又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
        return 1;
}

string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "云龙门")
                return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本派的云龙真经不在此处。";
        add("book_count", -1);
        ob = new("/clone/book/yljing2");
        ob->move(this_player());
        message("channel:rumor",HIM"【武林传奇】某人："+ this_player()->name()+"拿到云龙经了。\n"NOR,users());
        return "好吧，这本「云龙经」你拿回去好好钻研。";
}

void attempt_apprentice(object ob)
{

        command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是我辈中人，今天就收下你吧。");
        command("recruit " + ob->query("id"));
        if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))
                ob->set("class","fighter");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if(ob->query("weiwang")>=50)
        switch( random(3)){
                case 1:
                        say("玄贞笑道：这位" + RANK_D->query_respect(ob)+ "，我带你去香堂吧。\n");
                        ob->move("/d/city2/dating");
                        message_vision("$N来到了大厅。\n",ob);
                        break;
                default:
                        say("玄贞说道：这位" + RANK_D->query_respect(ob)+ "，请自便。\n");
                        break;
        }
        else say( "玄贞笑道：这位" + RANK_D->query_respect(ob)+ "，到这儿来干什么？\n");
}
