// mingji.c - 名妓
// Design By Robert 蝴蝶君 emial:robert_st@263.net

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("艳艳", ({ "yan yan","yan" }) );
        set("nickname",HIC"歌妓"NOR);
        set("long", @LONG
她是千金楼里出了名的名妓，在千金楼倍受宠爱。
LONG
);

	set("attitude", "friendly");
	set("gender", "女性" );
	set("age", 20);
	set("per", 30);

        set("combat_exp",random(40000)+10000);
	set("shen_type",-1);
        set("env/wimpy", 30);
        set("chat_chance",10);
        set("chat_msg",({
        	(: command("snicker") :),
        	(: command("xixi") :),
        }));
        setup();
        
	carry_object("/clone/cloth/green-silk")->wear();

        add_money("silver",5);
}
