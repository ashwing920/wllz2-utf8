#include <ansi.h>
inherit NPC;

void create()
{
	set_name("桑三娘", ({ "sang sanniang", "sang",}));
	set("long", @LONG
一名相貌慈祥的中年妇人，但杀起人来心狠手辣，绝不手软。
LONG
);
	set("title",HIW"日月神教白虎堂主"NOR);
	set("gender", "女性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);

	set("max_jing",1000);
	set("neili",1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp",100000);

	set_skill("tianmo-zhang",100);
	set_skill("tianmo-sword",100);
	set_skill("tianmo-dao",100);
	set_skill("piaomiao-shenfa",100);
	 set_skill("tianmo-dafa",100);

	map_skill("unarmed", "tianmo-zhang");
	map_skill("sword", "tianmo-sword");
	map_skill("parry", "tianmo-sword");
	map_skill("blade", "tianmo-dao");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "tianmo-dafa");
	create_family("日月神教",3,"弟子");

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
