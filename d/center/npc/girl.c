// girl.c - 女孩

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("女孩", ({ "girl" }) );
	set("long", @LONG
几个小女孩正在玩一条橡皮绳。
LONG
);

	set("attitude", "friendly");
	set("gender", "女性" );
	set("age", 13);
	set("combat_exp",1000);
	set("env/wimpy", 30);

	set_skill("unarmed", 20); 
	set_skill("parry",   20);
	set_skill("dodge",   20);

	set("chat_chance_combat", 30 );
	set("chat_msg_combat", ({
		(: command, "cry" :),
	}) );

	setup();
	carry_object("/clone/cloth/flower-silk")->wear();
}
