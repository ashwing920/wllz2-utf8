// yitaitai.c - 姨太太
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("姨太太", ({ "yi taitai" }) );
        set("long", @LONG
她是一个财主的姨太太。
LONG
);
	set("attitude", "friendly");
	set("gender", "女性" );
	set("age",25);

	set("str", 30);
	set("cps", 30);
	set("cor", 30);
	set("per", 30);
	set("con", 30);

        set("combat_exp",10000+random(30000));
        set("env/wimpy", 50);
        setup();
        
	carry_object("/clone/cloth/pink-silk")->wear();
        add_money("silver", 10);
}
