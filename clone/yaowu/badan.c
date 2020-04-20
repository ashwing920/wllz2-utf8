//Cracked by Kafei

#include <ansi.h>

inherit ITEM;

int cure_ob(string);

void create()
{
	set_name(RED "续命八丹" NOR, ({"xuming badan", "badan", "dan"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("value", 50000);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));

	if (me->query_condition("snake_poison") > 30)
		me->apply_condition("snake_poison", 0);

	if((int)me->query_condition("chanchu_poison")){
		if((int)me->query_condition("chanchu_poison") > 30)
			me->apply_condition("chanchu_poison",(int)me->query_condition("chanchu_poison") - 30);
		else
			me->clear_condition("chanchu_poison");
	}
	if((int)me->query_condition("xx_poison")){
		if((int)me->query_condition("xx_poison") > 30)
			me->apply_condition("xx_poison", me->query_condition("xx_poison") - 30);
		else
			me->clear_condition("xx_poison");
	}
	if((int)me->query_condition("hot_poision")){
		if((int)me->query_condition("hot_poison") > 30)
			me->apply_condition("hot_poison",(int)me->query_condition("hot_poison") - 30);
		else
			me->clear_condition("hot_poison");
	}
	message_vision(HIG "$N吃下一粒续命八丹，把命吊了回来！\n" NOR, me);
	destruct(this_object());
	return 1;
}
