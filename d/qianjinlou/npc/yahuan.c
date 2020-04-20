// yahuan.c - 丫环

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("丫环", ({ "ya huan" }) );
        set("long", @LONG
她是一名丫环。
LONG
);

	set("attitude", "friendly");
	set("gender", "女性" );
	set("age", 20);
	set("per", 28);
        set("combat_exp",10000);
	set("shen_type",1);
        set("env/wimpy", 30);

        setup();
        
	carry_object("/clone/cloth/mian-dress")->wear();	// 装备
}
