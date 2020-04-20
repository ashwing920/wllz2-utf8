// tiejiang.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("铁匠", ({ "tiejiang", "smith" }));
	set("title", "铁匠铺老板");
	set("shen_type", 1);

	set("gender", "男性" );
	set("age", 33);
	set("long", "这位铁匠正在叮叮当当地打着铁，发现你在注视着他，就抬起头来微笑了一下。\n");

	set("combat_exp", 400);
	set("attitude", "friendly");
	set("vendor_goods",([
		"/clone/weapon/gangdao": 20,
		"/clone/weapon/changjian": 20,
		"/clone/weapon/qimeigun": 20,
		"/clone/weapon/changbian": 20,
		"/clone/weapon/gangzhang": 20,
		"/clone/cloth/tiejia": 20,
	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_vendor_list", "list");
	 
}

