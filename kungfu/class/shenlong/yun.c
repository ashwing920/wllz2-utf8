// yunsumei.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("云素梅", ({"yun sumei", "yun"}));
	set("title",HIY"神龙教"HIR"赤龙使"NOR"座下弟子");
	set("long",@LONG
这是一个神龙教女弟子，一袭红衣，长得颇为可爱。
LONG
);

	set("gender", "女性");
	set("attitude", "peaceful");

	set("age", 10+random(10));
	set("shen_type",-1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_qi", 200);
	set("max_jing", 150);
	set("neili", 200);
	set("max_neili", 200);
	set("jiaji", 5+random(5));
	set("combat_exp", 20000+random(10000));

	set_skill("force", 100);
	set_skill("hand", 100);
	set_skill("strike", 100);
	set_skill("staff", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("leg",100);
	set_skill("finger",100);
	set_skill("yixingbu", 100);
	set_skill("jueming-tui",100);
	set_skill("poison",100);
	set_skill("yingxiong-sanzhao",100);
	set_skill("shenlong-bashi", 100);
	set_skill("huagu-mianzhang", 100);
	set_skill("shenlong-xinfa", 100);
	set_skill("shedao-qigong", 100);
	set_skill("sword",100);
	map_skill("finger","yingxiong-sanzhao");
	map_skill("leg","jueming-tui");
	map_skill("staff", "shedao-qigong");
	map_skill("force", "shenlong-xinfa");
	map_skill("hand", "shenlong-bashi");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "shedao-qigong");
	map_skill("dodge", "yixingbu");
	prepare_skill("hand", "shenlong-bashi");
	prepare_skill("strike", "huagu-mianzhang");

	setup();
	carry_object("/d/shenlong/obj/xionghuang")->wield();
	carry_object("/clone/weapon/duanjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver",5);
}

void init()
{
	object ob;

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting",10, ob);
	}
}

void greeting(object ob)
{
	object obj;

	if( !ob || environment(ob) != environment() ) return;
	if (interactive(ob)){
	if (obj = present("usedgao", ob))
		this_object()->unconcious();
	}
	return;
}
