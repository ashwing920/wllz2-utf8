// deer.c

inherit NPC;
#include <ansi.h>;

void create()
{
	set_name(YEL"梅花鹿"NOR, ({ "deer", "lu" }) );
	set("race", "野兽");
	set("age", 20);
	set("long", "一只温驯漂亮的梅花雄鹿。\n");
	set("attitude", "peace");
	set("combat_exp", 2000);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/armor", 10);
	setup();
}
