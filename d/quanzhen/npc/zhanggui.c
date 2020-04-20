
// zhanggui.c
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("掌柜", ({ "zhanggui", "gui" }));
	set("long",
		"这是位和和气气的生意人。\n");
	set("gender", "男性");
	set("age", 45);

	set("combat_exp", 7500);
	set_skill("unarmed", 35);
	set_skill("force", 35);
	set_skill("dodge", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 40);
	set("shen_type", 1);

	set("vendor_goods", ([
		__DIR__"obj/kaoya": 20,
		__DIR__"obj/jiudai": 20,
	]));

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver",20);
}

void init()
{
	 
	add_action("do_vendor_list", "list");
}
