// boy.c - 男孩

#include <ansi.h>

inherit NPC;

void create()
{

	set_name("男孩", ({ "boy" }) );
	set("long", @LONG
几个小男孩正在玩捉迷藏。
LONG
);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 15);

	set("combat_exp",1000);
	set("env/wimpy", 30);

	set_skill("unarmed",10); 
	set_skill("parry",  10);
	set_skill("dodge",  10);

	set("chat_chance_combat", 30 );
	set("chat_msg_combat", ({
		(: command, "cry" :),
	}) );

	setup();
	carry_object("/clone/cloth/gua-cloth")->wear();
}
