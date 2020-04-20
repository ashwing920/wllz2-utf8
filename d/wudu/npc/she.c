// dushe

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("毒蛇", ({ "dushe" }) );
	set("long","一支昂首吐信的毒蛇正虎视眈眈地盯著你。\n");
	set("race","蛇类");
	set("age",3);
	set("attitude","heroism");
	set("str", 10);
	set("cor", 50);
	set("lvl",50);
	set_temp("apply/attack", 10);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);
	set("combat_exp", 1000);
	setup();
}

int hit_ob(object me, object ob, int damage)
{
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&& (int)ob->query_condition("snake_poison") < 1 ) {
		ob->apply_condition("snake_poison", this_object()->query("lvl"));
		tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
	}
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave",0);
		return 1;
	}
	return ::heal_up() + 1;
}
void leave()
{
	if (!environment()) return;
	message("vision",name() +"嗖的一声，消失得无影无踪影。\n",environment(),this_object());
	destruct(this_object());
}
