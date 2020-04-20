// seller-cqp.c - 棺材铺老板
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("秦宝德", ({ "qin baode","qin","seller" }) );
	set("title","棺材店老板");
	set("long", @LONG
他就是棺材铺老板。一脸苍白，脸无表情，让人感到十分畏惧。
LONG
);

	set("rank_info/respect", "老板"); 
	set("attitude", "friendly");
	set("gender", "男性" );           
	set("age", 36);                   

	set("combat_exp", 50000+random(10000));
	set("env/wimpy", 30);

	set_skill("unarmed", 50); 
	set_skill("parry",   50);
	set_skill("dodge",   50);
	set("vendor_goods", ([
		__DIR__"obj/ghost_money":20,
		__DIR__"obj/ghost_flower": 20,
		"/clone/misc/paper_seal" : 20,
	]) );
	setup();
	
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver",10);
}

void init()
{       
	object ob;

	
		if( this_object()->query_temp("unconcious") ) return;
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(1) ) {
		case 0:
			say( this_object()->query("name") + "笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，想买什么东西吗？\n");
			break;
	}
}
