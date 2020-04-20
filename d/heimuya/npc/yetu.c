inherit NPC;

void create()
{
	set_name("野兔", ({ "ye tu", "ye", "hare" }) );
	set("race","野兽");
	set("age", 5);
	set("long", "一只好可爱的小野兔。\n");
	set("attitude", "peaceful");
	set("eatable",1);
	set("afterdie","/clone/food/hare-meat");
	set("combat_exp", 500);
	set("chat_chance", 6);
	set("chat_msg", ({
		(: random_move :),
	}) );

	set_temp("apply/attack", 2);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);

	setup();
}
