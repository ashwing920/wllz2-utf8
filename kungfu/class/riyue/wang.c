#include <ansi.h>

inherit NPC;

void create()
{
	set_name("王城", ({ "wang cheng", "wang",}));
	set("long",@LONG
此人身材矮胖，满脸堆笑，其实为人十分狠毒。
LONG
);
	set("title",HIY"日月神教风雷堂旗主"NOR);
	set("gender", "男性");
	set("age", 50);
	set("attitude", "heroism");
	set("vendetta_mark", "authority");
	set("pursuer", 1);
	set("shen_type", -1);
	set("str", 23);
	set("int", 23);
	set("con", 24);
	set("dex", 28);

	set("max_jing",1000);
	set("neili",1000);
	set("max_neili",1000);
	set("jiali",50);
	set("combat_exp",100000);

	set_skill("sword",100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("force",100);
	set_skill("tianmo-zhang",100);

	map_skill("unarmed", "tianmo-zhang");
	create_family("日月神教",3,"弟子");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
