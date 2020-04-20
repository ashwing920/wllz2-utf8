// huoji.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("药店伙计", ({ "yaodian huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是模样老老实实的年轻人。\n");
	set("combat_exp", 4250);
	set("attitude", "friendly");
	set("vendor_goods", ([
		"/clone/yaowu/jinchuang": 1,
		"/clone/yaowu/yangjing": 1,
		"/clone/yaowu/wuchangdan": 1,
		"/clone/drug/hedinghong": 1,
		"/clone/drug/bicanfeng": 1,
		"/clone/drug/kongquedan": 1,
	]));

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_vendor_list", "list");
	 
}
