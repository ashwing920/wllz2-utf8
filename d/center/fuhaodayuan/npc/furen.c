// furen.c 夫人

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("张夫人", ({ "zhang furen", "zhang" }));
        set("gender", "女性");
        set("long",@LONG
她是富豪院主人的大老婆张夫人。身材略微肥胖。
LONG
);
        set("per",30);
        set("age",45);

        set("combat_exp",20000);
        set("chat_chance",10);
        set("chat_msg",({
               CYN"张夫人说道：想打工的，可以找管家张万福(ask zhang about job)。\n"NOR,
               CYN"张夫人说道：想取消富豪大院短工或者丫环绰号的，可以找张万福(ask zhang about out)。\n"NOR,
        }));
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
        set("shen_type", -1);
        setup();

        add_money("silver",3);
        carry_object("/clone/cloth/cloth")->wear();
}
