//Cracked by Kafei
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "通犀地龙丸" NOR, ({"dilong wan", "wan"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long","这是一颗鸽蛋大小的黄色圆球，颜色沉暗，并不起眼。\n");
		set("value", 10000);
		set("medicine", 1);
	}

	setup();
}

int cure_ob(object me)
{

	message_vision("$N吃下一颗" + name() + "。\n", me);

	if((int)me->query_condition("xx_poison") > 0) {
		me->clear_condition("xx_poison");
	} 
	if((int)me->query_condition("snake_poison") > 0) {
		me->clear_condition("snake_poison");
	}
	if((int)me->query_condition("hg_poison") > 50){
		me->apply_condition("hg_poison",((int)me->query_condition("hg_poison") - 50));
	}
	destruct(this_object());
	return 1;
}