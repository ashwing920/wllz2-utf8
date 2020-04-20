//Cracked by Kafei
// /d/quanzhou/npc/seller2.c 摊贩
// Shan: 96/07/09

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("摊贩", ({ "tan fan", "seller", "fan" }) );
	set("gender", "男性" );
	set("age", 28);
	set("long",
"这是个机灵能干的小摊贩，摆弄着摊子里的各种武器，药品，大声向来往江湖客吆喝着。\n");
	set("shen_type", 1);
	set("combat_exp", 60000);
	set("str", 26);
	set("dex", 25);
	set("con", 22);
	set("int", 23);
	set("attitude", "peaceful");
	set("vendor_goods",([
		"/clone/weapon/changjian":1,
		"/clone/weapon/hammer":1,
		"/clone/weapon/stick":1,
		"/clone/weapon/zhubang":1,
		"/d/village/npc/obj/bottle":1,
		"/clone/food/jiudai":1,
		"/clone/food/kaoya":1,
	]) );
	setup();
	carry_object("clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_vendor_list", "list");
}

