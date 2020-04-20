inherit NPC;

void create()
{
	set_name("蝴蝶", ({ "hu die", "hu" }) );
	set("race", "昆虫");
	set("subrace","飞虫");
	set("age", 4);
	set("long", "一只美丽的蝴蝶，看到它，你不觉有些感伤。\n");
	set("attitude", "peaceful");
	set("str", 26);
	set("cor", 30);
	set("combat_exp", 1000);
	setup();
}
