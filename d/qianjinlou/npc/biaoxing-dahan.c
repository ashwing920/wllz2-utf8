// biaoxing-dahan.c - 彪形大汉

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("彪形大汉", ({ "biaoxing dahan", "dahan" }) );
        set("long", @LONG
他是一名彪形大汉。身材魁梧强壮，满脸络腮胡须，看样子十分凶恶。
LONG
);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age",23);
	set("str", 30);
        set("combat_exp",random(30000)+20000);
	set("shen_type",-1);
        set("env/wimpy", 30);			//
	set_skill("unarmed",50); 
	set_skill("parry",50);
	set_skill("dodge",50);

        setup();
        
	carry_object("/clone/cloth/red-pao")->wear();	// 装备
}
