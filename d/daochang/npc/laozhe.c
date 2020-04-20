// daochang-dizi.c - 道场长老

#include <ansi.h>

inherit NPC;

int ask_me();

void create()
{
        set("nickname",HIW"起死回生"NOR);
        set("title","蝴蝶谷");
        set_name("胡青牛", ({"hu qingniu","hu"}));
        set("long",@LONG
他就是蝴蝶谷神医的胡青牛，据说他精通医理，可以起死回生。
LONG);
        set("gender", "男性" );
        set("age",79);
        set("per",480);
        set("attitude", "heroism");

        set("age", 50);
        set("class", "shaman");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 27);
        set("con", 25);
        set("dex", 25);
        set("inquiry", ([
                "疗伤" : (:ask_me:),
        ]) );

        set("max_qi", 1500);
        set("max_jing", 600);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);
        set("combat_exp", 150000);
        set("score", 80000);

        set_skill("force", 90);
        set_skill("dodge", 90);
        set_skill("unarmed",90);
        set_skill("parry", 90);
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

int ask_me()
{
        object ob;
        ob=this_player();

        if ((int)ob->query("eff_qi") == (int)ob->query("max_qi"))
        {
                command("? "+ob->query("id"));    
                command("say 你没有受任何伤啊？\n");
                return 1;
        }
        else
        {
                message_vision("胡青牛喂$N服下一颗药丸，然后盘膝坐下，双掌贴着$N的背心。\n", ob);
                remove_call_out("recover");
                call_out("recover",2,ob);
                return 1;
        }
}


void recover(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        ob->set("eff_qi", (int)ob->query("max_qi"));
        ob->set("eff_jing", (int)ob->query("max_jing"));  
        tell_object(ob,"一股暖流游满了你全身上下的经脉；不一会儿，你的伤势已经恢复了。\n");
}
