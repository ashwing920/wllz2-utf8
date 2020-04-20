// younglady.c - 青年女子

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("青年女子", ({ "lady" }) );
        set("long", @LONG
她是一位正在热恋中的青年女子，正靠在她身边那男子
的肩膀上，一脸陶醉的样子。
LONG
);

	set("attitude", "friendly");
	set("gender", "女性" );
	set("age", 20);
	set("per", 28);

        set("combat_exp",20000+random(10000));
        set("env/wimpy", 30);
        setup();
        
	carry_object("/clone/cloth/luo-dress")->wear();	// 装备
}
