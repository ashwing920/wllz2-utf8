// guest.c 进香客

inherit NPC;

void create()
{
	set_name("进香客", ({ "jinxiang ke", "ke", "guest" }));
	set("gender", "男性");
	set("age",random(20) + 20);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set("apply/attack", 15);
	set("apply/defense", 15);
	set("apply/damage", 5);
	set("combat_exp", 15000);
	set("shen_type", 1);
	setup();
	add_money("silver",10);
}
	
