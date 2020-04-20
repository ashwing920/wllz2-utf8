// duck.c

inherit NPC;

void create()
{
	set_name("野鸭", ({ "duck" }) );
	set("race","飞禽");
	set("subrace","走禽");
	set("age", 1);
	set("long", "一只野鸭。\n");
	set_skill("dodge", 50);
	set("combat_exp", 500);
	setup();
}

