
// mujiang.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("木匠", ({ "mu jiang", "mu", "jiang" }) );
	set("gender", "男性" );
	set("age", 32);
	set("long",
		"这位木匠正在埋头工作，因为发现你在注视着他，就抬起头来微笑了一下。\n");
	set("combat_exp", 300);
	set("str", 17);
	set("dex", 20);
	set("con", 17);
	set("int", 22);
	set("attitude", "friendly");
	set("vendor_goods", ([
		__DIR__"obj/mujian": 20,
		__DIR__"obj/mudao": 20,
		__DIR__"obj/mugun": 20,
	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver",10);
}
void init()
{
	add_action("do_vendor_list", "list");
}

