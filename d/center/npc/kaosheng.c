// kaosheng.c - 考生

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("考生", ({ "kao sheng" }) );
	set("long", @LONG
他是前来应试的考生，脸色苍白，看起来好象十分紧张。
LONG
);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 18);

	set("combat_exp",30000);
	set("env/wimpy", 30);

	set_skill("unarmed",30); 
	set_skill("parry",30);
	set_skill("dodge",30);

	setup();
	carry_object("/clone/cloth/ma-cloth")->wear();
}
