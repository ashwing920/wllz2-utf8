// dushe.c
// cgm 1/12/1999
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("毒蛇", ({ "du she", "dushe", "she"}) );
	set("long", "一支昂首吐信的毒蛇正虎视眈眈地盯著你。\n");
	set("race","蛇类");
	set("age", 3);
	set("attitude", "peaceful");
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
void init()
{
	object me,ob;

	if (interactive(me = this_player()))
	{
	if (!(ob = present("xionghuang", this_player())))
	       {
	       remove_call_out("kill_ob");
	       call_out("kill_ob", 1, me);
		}
	}
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
