// duxie.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("毒蝎", ({ "du xie", "xie" }) );
	set("long", "一只全身黑乎乎，尾巴翘得高高的蝎子。\n");
	set("race","昆虫");
	set("subrace","爬虫");
	set("age", 3);
	set("attitude", "aggressive");
	set("max_jing", 300);
	set("max_qi", 500);
	set("str", 30);
	set("cor", 50);
	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 20);
	set("combat_exp", 20000);
	setup();
}

int hit_ob(object me, object ob, int damage)
{
    if ((int)ob->query("combat_exp") > 20000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&      (int)ob->query_condition("snake_poison") < 10 ) {
		ob->apply_condition("snake_poison", 20);
	tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
	}
}
