#include <ansi.h>
inherit NPC;

void create()
{
	set_name("司马大", ({ "si mada", "si",}));
	set("long",@LONG
这大汉身材魁梧之极，巨人般的身体在走动时，脚步声极之沉重，整个地
板都为之震动。
LONG
);
	set("nickname",HIG"日月神教青龙堂舵主"NOR);        
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
	
	map_skill("unarmed", "tianmo-zhang");
	create_family("日月神教", 3, "弟子");
	setup();
	carry_object("clone/weapon/staff")->wield();
	carry_object("clone/cloth/cloth")->wear();        
}
