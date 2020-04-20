// chaxiaoer

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("茶小二", ({ "xiao er", "xiao" }));
	set("shen_type", 1);
	set("str", 30);
	set("gender", "男性");
	set("age", 25);
	set("long","这个茶小二正忙着给客人送茶。");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("vendor_goods", ([
		__DIR__"obj/yan": 20,
		__DIR__"obj/wan": 20,
	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	object ob;
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())return;
	switch(random(2)) {
		case 0 :
		say("茶小二热情的说到：这位" + RANK_D->query_respect(ob) +"，马上给你上茶。\n");
		break;
		case 1 :
		say("茶小二说道：这位" + RANK_D->query_respect(ob) + "要不要来两口水烟提提神。\n");
		break;
	}
}
