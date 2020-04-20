//Cracked by Kafei
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "田七鲨胆散" NOR, ({"tianqi san", "san"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "：这是一包田七鲨胆散，可解剧毒。\n");
		set("value", 10000);
		set("medicine", 1);
	}
	setup();
}
int cure_ob(object me)
{
	if (me->query_condition("cool_drug") > 0){        
		message_vision(HIR "$N吃下一包"+name()+"，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
		destruct(this_object());
		return 1;
	}
	message_vision("$N吃下一包" + name() + "。\n", me);
	if((int)me->query_condition("xx_poison") < 30) {
		me->clear_condition("xx_poison");
	} else if ((int)me->query_condition("xx_poison") >= 30)
		me->apply_condition("xx_poison", (int)me->query_condition("xx_poison")-5);
   
	if ((int)me->query_condition("snake_poison") > 0) {
		me->clear_condition("snake_poison");
	}

	me->apply_condition("cool_drug", 10);
	destruct(this_object());
	return 1;
}

