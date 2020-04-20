// smith.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("铁匠", ({ "tiejiang", "smith" }));
	set("title", "铁匠铺老板");
	set("gender", "男性" );
	set("age", 33);
	set("long", "铁匠正用铁钳夹住一块红热的铁块放进炉中。\n");

	set("combat_exp", 4000);
	set("attitude", "friendly");
	set("vendor_goods",([
		"/clone/weapon/tiejia": 20,
		"/clone/weapon/changjian": 20,
		"/clone/weapon/hammer": 20,
		"/d/city2/obj/tudao": 20,
		"/clone/weapon/dagger": 20,
		"/d/xingxiu/obj/tiegun": 20,
		"/clone/weapon/gangdao": 20,
	]));

	setup();

	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_vendor_list", "list");
	 
}

