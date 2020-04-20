// huoji. 药铺伙计

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("药铺伙计", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是平神医从乡下招来帮忙的。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ([
		"/clone/yaowu/jinchuang": 1,
		"/clone/yaowu/yangjing": 1,
		"/clone/yaowu/wuchangdan": 1,
		"/clone/misc/dust": 1,
		"/d/shenlong/obj/xionghuang": 1,
		"/clone/yaowu/lingzhi": 1,
	]));

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	add_action("do_vendor_list", "list");
}
