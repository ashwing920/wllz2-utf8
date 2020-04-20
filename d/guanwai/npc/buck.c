// buck.c

inherit NPC;
#include <ansi.h>;

void create()
{
	set_name(YEL"梅花雄鹿"NOR, ({ "meihua xionglu", "buck", "lu" }) );
	set("race", "野兽");
	set("age", 20);
	set("long", "一只温驯的梅花雄鹿，正在低头吃草。\n");
	set("attitude", "peace");
	set("shen_type", -1);
	set("combat_exp", 2000);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/armor", 10);

	setup();
}
