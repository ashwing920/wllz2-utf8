// woman.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit NPC;

void create()
{
	set_name("樵夫", ({ "qiao fu","qiao","fu" }) );
	set("gender", "男性" );
	set("age", 33);
	set("long", "一个很健壮的樵夫。\n");
	set("shen_type", 1);
	set("combat_exp", 800);
	set("str", 22);
	set("dex", 18);
	set("con", 18);
	set("int", 18);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/d/baituo/obj/chai");
	carry_object("/d/baituo/obj/chaidao")->wield();
}

