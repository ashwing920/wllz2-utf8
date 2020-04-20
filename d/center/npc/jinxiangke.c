// jinxiangke.c - 进香客
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("进香客", ({ "jinxiang ke", "ke" }));
        set("long", @LONG
这是一位进香客。
LONG
);

	set("attitude", "friendly");
        set("gender", "男性" );
        set("age", 36);

        set("combat_exp",10000+random(10000));
        set("env/wimpy", 30);			

	set_skill("unarmed", 20); 
	set_skill("parry",   20);
	set_skill("dodge",   20);

        setup();
        
	carry_object("/clone/cloth/cloth")->wear();	// 装备

        add_money("silver", 10);			// 金钱
}
