// nianqing-gongzi.c - 年青公子

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("年青公子", ({ "nianqing gongzi", "gongzi" }) );
        set("long", @LONG
他是一名年青公子。
LONG
);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 24);
	set("per", 28);
        set("combat_exp",10000+random(30000));

        set("env/wimpy", 30);

        setup();
        
	carry_object("/clone/cloth/cloth")->wear();	// 装备
}
