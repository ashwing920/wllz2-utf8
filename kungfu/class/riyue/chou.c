
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("仇松年", ({ "chou songnian", "chou",}));
	set("long",@LONG
这头陀长发垂肩，头上戴着一个闪闪发光的铜箍，束着长发。
LONG
);
	set("nickname",RED"日月神教朱雀堂旗主"NOR);        
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);
	
	set("max_jing",1000);
	set("neili",1000);
	set("max_neili",1000);
	set("jiali", 50);
	set("combat_exp",100000);
	
	set_skill("wuchang-zhang",100);
	set_skill("tianmo-zhang",100);
	set_skill("tianmo-sword",100);
	set_skill("tianmo-dao",100);        
	set_skill("piaomiao-shenfa",100);
	set_skill("tianmo-dafa",100);

	map_skill("unarmed", "tianmo-zhang");
	map_skill("staff", "wczhang");
	map_skill("parry", "tianmo-sword");
	map_skill("blade", "tianmo-dao");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "tianmo-dafa");
	create_family("日月神教",3,"弟子");
	setup();
	carry_object("clone/weapon/staff")->wield();
	carry_object("clone/cloth/cloth")->wear();        
}