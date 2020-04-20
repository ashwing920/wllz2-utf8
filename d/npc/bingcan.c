// bingcan.c
// cgm 4/12/1999

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(HIW"冰蚕"NOR, ({ "bing can", "can" }) );
	set("long", HIC"一条通体透明小蚕。\n"NOR);
	set("race","昆虫");
	set("subrace","爬虫");
	set("age", 1000);
	set("attitude", "aggressive");
	set("max_jing", 1500);
	set("max_qi", 8000);
	set("str", 100);
	set("cor", 50);
	set("dex", 100);
	set("combat_exp", 500000);
	set_temp("apply/attack", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/defence",50);
	setup();
}

int hit_ob(object me, object ob, int damage)
{
    if ((int)ob->query("combat_exp") > 1000000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&      (int)ob->query_condition("can_poison") < 50 ) {
		ob->apply_condition("can_poison", 60);
	tell_object(ob, HIW "一阵刺骨的寒气从伤口一直传进你的身体！\n" NOR );
	}
}
