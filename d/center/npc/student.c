// student.c - 学生
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("学生", ({ "student" }) );
        set("nickname",HIW"学海无崖"NOR + CYN"苦作舟"NOR);
        set("long", @LONG
他是一位学生。
LONG
        );

        set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 16);
        set("combat_exp",10000+random(30000));
        set("env/wimpy", 30);

        setup();
        
        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver",10);
}
