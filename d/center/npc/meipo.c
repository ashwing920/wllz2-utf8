// mei_po.c
#include <ansi.h>
#include <marry.h>

inherit NPC;

void create()
{
	set_name("媒婆", ({ "mei po" }));
	set("long", @LONG
一位精明能干的老媒婆。不知为人操办了多少次婚事。
LONG
);
	set("title", "红娘庄");
	set("rank_info/respect", "老婆婆");
	set("attitude", "friendly");
	set("gender", "女性" );
	set("age", 45);
	set("per", 25);
	set("startroom","/d/center/hongniangzhuang");

	set("combat_exp",50000+random(50000));
	set("env/wimpy", 50);
	set("inquiry", ([
		"婚约" 	   : "是啊....这里就可以缔结和解除婚约。",
	]) );

	setup();
	
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/cloth/silver-clasp")->wear();

	add_money("silver",20);
}

void init()
{
	add_action("do_marry", "marry");
	add_action("do_unmarry", "unmarry");
	add_action("do_name","拜");
}
