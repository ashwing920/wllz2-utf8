// banjiu.c

inherit NPC;

void create()
{
	set_name("斑鸠", ({ "ban jiu"}));
	set("race","飞禽");
	set("age", 3);
	set("long", "一只小斑鸠，在田地间跳上跳下。\n");
	set("attitude", "peaceful");
	set("combat_exp", 300);
	set_temp("apply/attack", 3);
	set_temp("apply/defense", 5);
	set_temp("apply/armor", 1);
	setup();
}
