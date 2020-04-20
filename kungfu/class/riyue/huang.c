#include <ansi.h>
inherit NPC;

void create()
{
	set_name("黄伯流", ({ "huang boliu", "huang",}));
	set("nickname", "银髯蛟");        
	set("long", @LONG
此人头上罩着黑色头罩，根本看不见相貌显得十分诡秘。
LONG
);
	set("title",HIY"日月神教风雷堂香主"NOR);        
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);
	
	set("max_jing",2000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",150);
	set("combat_exp",800000);
       
	set_skill("tianmo-zhang",200);
	set_skill("tianmo-sword",200);
	set_skill("tianmo-dao",200);        
	set_skill("piaomiao-shenfa",200);
	set_skill("tianmo-dafa",200);

	map_skill("unarmed", "tianmo-zhang");
	map_skill("sword", "tianmo-sword");
	map_skill("parry", "tianmo-sword");
	map_skill("blade", "tianmo-dao");
	map_skill("dodge", "pimiao-shenfa");
	map_skill("force", "tianmo-dafa");
	map_skill("unarmed", "tianmo-zhang");
	create_family("日月神教",3,"弟子");
	setup();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
