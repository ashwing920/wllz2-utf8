// smith.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("铁匠", ({ "tiejiang", "smith" }));
	set("shen_type", 1);
	set("gender", "男性" );
	set("age", 33);
	set("long", "铁匠正用汗流浃背地打铁。\n");
	set("combat_exp", 55000);
	set("attitude", "friendly");
	set("vendor_goods",([
		"/d/baituo/obj/dadao": 20,
	]));

	setup();
	carry_object("/clone/cloth/cloth")->wear();

}

void init()
{
	add_action("do_vendor_list", "list");

}

