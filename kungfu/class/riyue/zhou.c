
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("周孤桐", ({ "zhou gutong", "zhou",}));
	set("nickname",HIM"日月神教朱雀堂舵主"NOR);
	set("long",@LONG
他那一张品黄的脸上对你发出一阵阴笑。
LONG
);

	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 23);
	set("int", 23);
	set("con", 24);
	set("dex", 28);

	set("max_jing",1000);
	set("neili",1000);
	set("max_neili",1000);
	set("jiali", 50);
	set("combat_exp", 100000);

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
	carry_object("clone/weapon/staff")->wield();
	carry_object("clone/cloth/cloth")->wear();
}
