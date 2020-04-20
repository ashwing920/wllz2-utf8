#include <ansi.h>
inherit NPC;

void create()
{
	set_name("游讯", ({ "you xun", "xun",}));
	set("nickname", "滑不留手");        
	set("long",@LONG
这人头顶半秃，一部黑须，肥肥胖胖，满脸红光，神情十分和蔼可亲。
LONG
);
	set("title",GRN"日月神教青龙堂旗主"NOR);        
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);
	
	set("max_qi", 700);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 100000);
       
	set_skill("tianmo-zhang",80);
	set_skill("tianmo-dao",80);        
	set_skill("piaomiao-shenfa",80);
	set_skill("tianmo-dafa",80);

	map_skill("unarmed", "tianmo-zhang");
	map_skill("blade", "tianmo-dao");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "tianmo-dafa");
	create_family("日月神教",3,"弟子");
	setup();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/cloth/cloth")->wear();        
}
