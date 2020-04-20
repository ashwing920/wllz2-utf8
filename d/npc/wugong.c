// wugong.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("蜈蚣", ({ "wu gong", "wu", "gong" }) );
	set("long", "一条全身赤红的蜈蚣，看来剧毒非常。\n");
	set("race", "昆虫");
	set("subrace","爬虫");
	set("age", 3);
	set("attitude", "aggressive");
	set("max_jing", 300);
	set("max_qi", 500);
	set("str", 30);
	set("cor", 50);
	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 20);

	set("combat_exp", 20000);
	setup();
}
