// peijiu-nu.c - 陪酒女郎

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("陪酒女郎", ({ "peijiu nulang", "nulang" }) );
        set("long", @LONG
她是一名陪酒女郎。两腮绯红，看起来是喝了不少酒。
LONG
);

	set("attitude", "friendly");
	set("gender", "女性" );
	set("age", 20);

	set("per", 28);

        set("combat_exp",10000+random(20000));
	set("shen_type",1);

        set("env/wimpy", 30);

        setup();
        
	carry_object("/clone/cloth/green-dress")->wear();	// 装备
}
