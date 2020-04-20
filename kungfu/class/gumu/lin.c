// lin.c 林朝英

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_yunv();

void create()
{
        set_name("林朝英", ({"lin chaoying", "lin"}));
        set("gender", "女性");
        set("age", 42);
        set("long",@LONG
她就是古墓新派的开山祖师林朝英，虽然已经是四十许人，望之却还如同
三十出头。当年她与全真教主王重阳本是一对痴心爱侣，只可惜有缘无份
，只得独自在这古墓上幽居。
LONG
);
        set("attitude", "friendly");
        set("per", 30);
        set("str", 37);
        set("int", 42);
        set("con", 45);
        set("dex", 42);

        set("chat_chance_combat", 6);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
        }));

        set("jing",10000);
        set("max_jing",10000);
        set("neili",12000);
        set("max_neili",12000);
        set("jiali",600);

        set("combat_exp",51200000);

        set_skill("force", 800);
        set_skill("yunv-xinfa", 800);
        set_skill("qufeng",800);
        set_skill("sword", 800);
        set_skill("yunv-jian", 800);
        set_skill("quanzhen-jian",800);
        set_skill("dodge", 800);
        set_skill("yunv-shenfa", 800);
        set_skill("parry", 800);
        set_skill("unarmed",800);
        set_skill("meinv-quan", 800);
        set_skill("literate",800);
        set_skill("taoism",800);
        set_skill("tianluo-diwang",800);

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");

        create_family("古墓新派", 1, "开山祖师");

        set("book_count",1);
        set("inquiry", ([
                "王重阳" :  "大胆后辈小子，也敢直呼重阳祖师之名？\n",
                "重阳祖师" : "重阳是全真教的掌教，自号“活死人”。\n",
                "古墓新派" :  "是啊，这里就是我一手创下的古墓新派\n",
                "玉女心经" : (: ask_yunv :),
        ]) );
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/gumu/npc/obj/qingyi")->wear();

}
void attempt_apprentice(object ob)
{
        if (ob->query_int() < 30) {
                command("say 我古墓新派的功夫最讲一个悟字，你的资质不够。");
                return;
        }
        if ((int)ob->query_skill("yunv-xinfa",1) < 300 ) {
                command("say 你的玉女心法火候不足，难以领略更高深的武功。");
                return;
        }
        command("say 好吧，看你也是性情中人，我就收下你这个徒弟了。");
        command("recruit " + ob->query("id"));
}

string ask_yunv()
{
        mapping fam;
        object ob;
        int lvl_yunv;
        lvl_yunv = this_player()->query_skill("yunv-xinfa",1);

        if (!(fam = this_player()->query("family"))|| fam["family_name"] != "古墓新派")
                return RANK_D->query_respect(this_player()) +"与本派毫无瓜葛，何以问起本派的心经？";
        if (!lvl_yunv || lvl_yunv < 55)
                return RANK_D->query_respect(this_player()) +"的玉女心法火候不足，我不能将玉女心经交给你";
        if (query("book_count") < 1)
                return "你来晚了，本派的玉女心经已经被人取走了。";
        add("book_count", -1);
        ob = new("/clone/book/yunvjing2");
        ob->move(this_player());
        CHANNEL_D->do_channel(this_object(),"rumor",sprintf("%s拿到玉女心经啦！",this_player()->name(1)));
                return "好吧，这本「玉女心经」你拿回去好好研读。";
}

