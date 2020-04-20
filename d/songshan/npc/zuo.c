// zuo.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
	set_name("左冷禅", ({ "zuo lengchan", "zuo" }) );
	set("title", HIR"五岳剑派盟主"HIY"嵩山派第十三掌门"NOR);
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 55);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 30);
	set("max_qi",2000);
	set("max_jing",1200);
	set("combat_exp", 1200000);

	set_skill("unarmed", 150);
	set_skill("sword", 150);
	set_skill("force", 150);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("songshan-sword", 150);
	set_skill("lingxu-bu", 150);

	map_skill("sword", "songshan-sword");
	map_skill("parry", "songshan-sword");
	map_skill("dodge", "lingxu-bu");

	create_family("嵩山派", 13, "掌门");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

