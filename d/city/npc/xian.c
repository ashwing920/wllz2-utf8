// xian. 冼老板

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("冼老板", ({ "xian laoban", "xian" }));
	set("title", "醉仙楼老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 45);
	set("long", "洗老板经营祖传下来的醉仙楼已有多年。\n");
	set("combat_exp", 50000);
	set("qi", 300);
	set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set("vendor_goods", ([
		"/clone/food/jiudai": 20,
		"/clone/food/kaoya": 20,
	]));

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_vendor_list", "list");
}

