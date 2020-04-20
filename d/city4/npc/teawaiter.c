// teawaiter.c 

inherit NPC;
inherit F_VENDOR;

void  create()
{
	set_name("茶博士",  ({"cha boshi","waiter"}));
	set("shop_id",  ({"boshi",  "waiter"}));
	set("gender",  "男性");
	set("class",  "scholar");
	set("combat_exp",  1000);
	set("age",  26);
	set("per",  14);
	set("attitude",  "friendly");
	set("shen_type",  1);
	set_skill("unarmed",  10);
	set("vendor_goods",  ([
		"/clone/food/jiudai": 20,
		"/clone/food/jitui": 20,
	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
void  init()
{
	add_action("do_vendor_list",  "list");
}
