// 毒蛇 dushe.c

inherit NPC;

void create()
{
	set_name("毒蛇", ({ "du she", "she" }) );
	set("race", "蛇类");
	set("age", 1);
	set("long", "一只有毒的花斑蛇。\n");
	set("attitude", "aggressive");
	set("combat_exp", 100);
	set("afterdie","/d/wudu/obj/shedan");
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 15);
	set_temp("apply/armor", 10);
	setup();
}
