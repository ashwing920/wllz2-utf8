// teacher.c - 教书先生
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("教书先生", ({ "teacher" }) );
        set("nickname",HIG"书中自有颜如玉"NOR);
        set("long", @LONG
他是一位博学多闻的教书先生。他年轻时曾经中过举人，但是因为生性喜
爱自由而不愿做官。他以教书为业，如果你付他一笔学费，就可以成为他
的弟子学习读书识字。
LONG
);
        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 65);
        set("per", 28);

        set("combat_exp",30000+random(10000));
        set("shen_type",1);

        set("env/wimpy", 30);
        set_skill("literate", random(100) + 50);
        set("inquiry", ([
                "学费"     : "嗯....知识是无价的，不过如果你有心的话——只要十两银子。\n",
                "读书识字" : "对，读书识字。",
        ]) );

        setup();

        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/cloth/boots")->wear();     

        add_money("silver",10);
}


int recognize_apprentice(object ob)
{
        if( !ob->query("marks/教书先生") ){
                command("?" );
                command("say 咦？我不记得收过你这个学生啊....\n");
                return 0;
        }

        return 1;
}

int accept_object(object who, object ob)
{
        if( !who->query("marks/教书先生") ) {
                if( ob->value() >= 1000 ) {
                        command("nod " + who->query("id") );
                        command("say 很好，从今天起你随时可以来问我有关读书识字(literate)的任何问题。");
                        who->set("marks/教书先生", 1);
                        return 1;
                } else {
                        command("hehe " + who->query("id") );
                        command("say 你的诚意不够，这钱还是拿回去吧。");
                        return 0;
                }
        } else {
                command("nod " + who->query("id") );
                command("say 哦，象你这麽有心的学生还真是不多见，好好努力将来必定前途无量，谢了。");
        }

        return 1;
}
