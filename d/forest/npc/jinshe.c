//jinshe.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("金环蛇", ({ "jin she", "she" }) );
	set("race", "蛇类");
	set("age", 2);
	set("long", "一只让人看了起毛骨悚然的金环蛇。\n");
	set("attitude","aggressive");
	set("str", 20);
	set("cor", 20);
	set("combat_exp", 1500+random(200));
	set("eatable",1);
	set("afterdie","/d/baituo/obj/jindan");
	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",15);
	setup();
}
int hit_ob(object me, object ob, int damage)
{
	if ((int)ob->query("combat_exp") > 10000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&      (int)ob->query_condition("snake_poison") < 10 ) {
		ob->apply_condition("snake_poison", 20);
	tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
	}
}
