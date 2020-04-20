// jinshe.c
// cgm 1/12/1999

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("银环蛇", ({ "yin she", "she" }) );
	set("race", "蛇类");
	set("age", 2);
	set("long", "一条让人看了起毛骨悚然的银环蛇。\n");
	set("attitude", "peaceful");
	set("str", 50);
	set("cor", 50);
	set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
	set("verbs", ({ "bite" }) );
	set("max_jing", 800);
	set("max_qi", 3000);
	set("combat_exp", 100000);
	set_temp("apply/attack", 20+random(10));
	set_temp("apply/damage", 20+random(10));
	set_temp("apply/armor", 20+random(10));
	set_temp("apply/defence",20+random(10));
	setup();
}

void init()
{
	object ob;

	if (interactive(this_player()))
	{
		if (!(ob = present("xionghuang", this_player())))
		{
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, this_player());
		}
	}
}

int hit_ob(object me, object ob, int damage)
{
    if ((int)ob->query("combat_exp") > 200000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&      (int)ob->query_condition("snake_poison") < 30 ) {
		ob->apply_condition("snake_poison", 40);
	tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
	}
}