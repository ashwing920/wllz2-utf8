// hongniang.c - 红娘
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("红娘", ({ "hong niang", "hong" }) );
        set("long", @LONG
她是为人操办婚事红娘。
LONG
);

	set("gender", "女性" );
	set("age", 20);
	set("per", 30);

        set("combat_exp",20000+random(20000));
        set("env/wimpy", 30);
        setup();
        
	carry_object("/clone/cloth/red-silk")->wear();
}
