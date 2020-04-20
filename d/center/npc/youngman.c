// youngman.c - 青年男子
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit NPC;

void create()
{

	set_name("青年男子", ({ "man" }) );
        set("long", @LONG
这是一个青年男子，正和身边的那女子窃窃私语呢。
LONG
);
	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 24);
	set("per", 28);

        set("combat_exp",20000+random(10000));
        set("env/wimpy", 30);

        setup();
        
	carry_object("/clone/cloth/white-pao")->wear();	// 装备
}
