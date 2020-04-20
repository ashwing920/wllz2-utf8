// chaofeng.c

#include <ansi.h>

inherit NPC;
inherit F_PAWN;
inherit F_DEALER;

int redeem(string arg);

void create()
{
	set_name("老朝奉", ({ "lao chaofeng", "chaofeng" }));
	set("title", "当铺老板");
	set("gender", "男性");
	set("age", 35);
	set("long", "一个衣着光鲜的老朝奉。\n");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_value", "value");
	add_action("do_pawn", "pawn");
	add_action("do_sell", "sell");
	add_action("do_redeem", ({ "redeem", "ransom" }) );
	add_action("do_vendor_list","list");

}
