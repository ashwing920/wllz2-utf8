// honglingbo.c 洪凌波

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("洪凌波", ({"hong lingbo","hong"}));
	set("gender", "女性");
	set("age", 22);
	set("long",@LONG
她是古墓派的传人洪凌波。
LONG
);
	set("attitude", "friendly");
	set("per", 30);
	set("str", 30);
	set("int", 37);
	set("con", 36);
	set("dex", 38);

	set("chat_chance_combat",60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "duo" :),
		(: perform_action, "you" :),
	}) );

	set("shen_type",1);
	set("jing",3000);
	set("max_jing",3000);
	set("jingli",3000);
	set("max_jingli",3000);

	set("combat_exp",2700000);

	set_skill("force", 300);
	set_skill("yunv-xinfa", 300);
	set_skill("sword", 300);
	set_skill("yunv-jian", 300);
	set_skill("quanzhen-jian",300);
	set_skill("dodge", 300);
	set_skill("yunv-shenfa", 300);
	set_skill("parry", 300);
	set_skill("hubo", 300);
	set_skill("unarmed",300);
	set_skill("meinv-quan",300);
	set_skill("literate",300);
	set_skill("qufeng",300);
	set_skill("tianluo-diwang",300);

	map_skill("force", "yunv-xinfa");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "meinv-quan");

	create_family("古墓新派", 3, "弟子");



	set("env/wimpy", 40);
	setup();

	carry_object("/d/gumu/npc/obj/shunvjian")->wield();
	carry_object("/d/gumu/npc/obj/baipao")->wear();

}
