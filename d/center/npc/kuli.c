// kuli.c - 苦力

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(npc_name("男性"), ({ "ku li" }) );
	set("title","苦力");
        set("long", @LONG
这是一个苦力。
LONG
);
	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 28);

	set("str", 30);				// 膂力	
        set("combat_exp", random(30000)+10000);
	set("shen_type",1);

        set("env/wimpy", 30);

        setup();
        
	carry_object("/clone/cloth/cloth")->wear();	// 装备
}
