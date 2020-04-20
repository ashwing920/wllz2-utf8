// cow.c 大黄牛

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIW"大黄牛"NOR, ({ "cow" }));
	set("long","一头大黄牛。\n");
	set("race", "家畜");
	set("age", 5);
	set("int", 30);
	set("ridable",1);
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 100);
	set("max_jing", 100);
	set("combat_exp",50000);
	set("attitude", "peaceful");
	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);
	setup();
}

