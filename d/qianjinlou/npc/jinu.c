// jinu.c - 妓女

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("妓女", ({ "ji nu" }) );
        set("long", @LONG
她是一名青楼女子，浓妆艳抹，不时透出阵阵幽香。
LONG
);

	set("attitude", "friendly");
	set("gender", "女性" );
	set("age", 20);
	set("per",random(10)+20);

        set("combat_exp",random(30000)+10000);
	set("shen_type",1);
        set("env/wimpy", 30);
        setup();
        
	carry_object("/clone/cloth/red-dress")->wear();

        add_money("silver",1);
}
