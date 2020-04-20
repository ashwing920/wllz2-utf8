//Cracked by Kafei

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("怪蛇", ({ "guai she", "she", "snake" }) );
	set("race", "蛇类");
	set("age", 4);
	set("long", "一条银光闪闪的小蛇，产于西域，极为罕见。\n");
	set("attitude", "peaceful");
	set("str", 30);
	set("cor", 30);
	set("dex", 35);
	set("combat_exp", 100000);
	set_temp("apply/attack", 55);
	set_temp("apply/damage", 56);
	set_temp("apply/armor", 52);

	setup();
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("snake_poison", 10 + me->query("snake_poison") + victim->query_condition("snake_poison"));
}
