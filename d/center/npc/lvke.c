// lvke.c

#include <ansi.h>

inherit NPC;

void create()
{
	switch(random(3)){
		case 0:
			set("title","游客");
			set_name(npc_name("男性"),({"you ke"}));
			break;
		case 1:
			set("title", "旅客");
			set_name(npc_name("男性"),({"lv ke"}));
			break;
		case 2:
			set("title", "富商");
			set_name(npc_name("男性"),({"fu shang"}));
			break;
	}
	set("long", @LONG
一副富家人打扮，看起来是个生意人。
LONG
);

	set("attitude", "friendly");
	set("age", 34);
	set("gender", "男性");
	set("chat_chance",5);
	set("chat_msg",({
		(: random_move :),
	}));
	set("combat_exp",random(40000)+ 10000);
	set("shen_type",1);
	set("env/wimpy",30);

	set_skill("unarmed",random(50));
	set_skill("parry",random(50));
	set_skill("dodge",random(50));
	set_skill("literate",random(50));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
