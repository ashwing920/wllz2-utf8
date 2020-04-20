#include <ansi.h>
inherit NPC;

void create()
{
	set_name("祖千秋", ({ "zu qianqiu", "zu",}));
	set("nickname",HIM"日月神教风雷堂坛主"NOR);
	set("long",@LONG
只见他面皮焦黄，双目无神，疏疏落落有几根胡子，身材颇瘦削，却挺着
个大肚子。
LONG
);
	set("age", 80);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);

	set("max_jing",1000);
	set("neili",1000);
	set("max_neili",1000);
	set("jiali",100);
	set("combat_exp", 100000);

	set_skill("tianmo-zhang",100);
	set_skill("piaomiao-shenfa",100);
	set_skill("tianmo-dafa",100);

	map_skill("unarmed", "tianmo-zhang");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "tianmo-dafa");
	create_family("日月神教",3,"弟子");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/staff")->wield();
}
