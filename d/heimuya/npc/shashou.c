#include <ansi.h>
inherit NPC;

void create()
{
	set_name("黑衣杀手", ({ "heiyi shashou", "shashou"}));
	set("long",@LONG
只见他容貌清瘦，颏下疏疏朗朗一丛花白长须，垂在胸前，腰间悬着一柄
弯刀。
LONG
);
	set("title","日月神教风雷堂第子");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "heroism");
	set("pursuer", 1);
	set("shen_type",-1);
	set("str", 23);
	set("int", 23);
	set("con", 24);
	set("dex", 28);
	
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili",1000);
	set("jiali",50);
	set("combat_exp",100000);

	set_skill("sword", 100); 
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("force",100);
	set_skill("tianmo-zhang",100);
	
	map_skill("unarmed", "tianmo-zhang");
	create_family("日月神教",3,"弟子");      

	set("chat_chance",10);
	set("chat_msg",({
		(: random_move :),
	}));
	setup();
}   
