// ren-fanzi.c - 人贩子

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("人贩子", ({ "ren fanzi", "fanzi" }) );
        set("long", @LONG
他是一名人贩子。经常拐卖良家妇女到这里来，卖做青楼女子。
LONG
);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 24);

        set("combat_exp",random(40000)+30000);
	set("shen_type",-1);

        set("env/wimpy", 30);

	set_skill("unarmed",60); 
	set_skill("parry",60);
	set_skill("dodge",60);

        setup();
        
	carry_object("/clone/cloth/cloth")->wear();	// 装备

        add_money("gold", 1);				// 金钱
}
