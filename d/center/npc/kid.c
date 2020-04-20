// kid.c - 小童
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("小童", ({ "kid" }) );
        set("title",HIY"天真"HIW"活泼"NOR);
        set("long", @LONG
小童一脸天真正对着你微笑。
LONG
);
        set("attitude", "friendly");
        set("gender", "男性" );
        set("age",13);
        set("combat_exp",1000);
        set("env/wimpy", 60);
        setup();
        carry_object("/clone/cloth/du-cloth")->wear();
}
