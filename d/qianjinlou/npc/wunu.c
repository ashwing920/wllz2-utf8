// wunu.c - 舞女

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("舞女", ({ "wu nu" }) );
        set("long", @LONG
她是一名舞女。
LONG
);

        set("attitude", "friendly");
        set("gender", "女性" );
        set("age", 20);
        set("per", 28);

        set("chat_chance",5);
        set("chat_msg",({
              (: command("taoyan jian shang") :),
              (: command("ppp jian shang") :),
        }));
        set("combat_exp",10000+random(10000));
        set("shen_type",-1);

        set("env/wimpy", 30);

        setup();
        
        carry_object("/clone/cloth/red-dress")->wear(); // 装备
}
