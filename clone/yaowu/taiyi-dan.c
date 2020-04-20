//Cracked by Kafei

#include <ansi.h>

inherit ITEM;

int cure_ob(string);

void create()
{
	set_name(HIC"太乙紫金丹"NOR, ({"taiyi zijindan","zijin dan","dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("value", 3500);
		set("long", "这是一颗太乙紫金丹，可以让人神游太虚，身形缥缈。\n");
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	message_vision("$N吃下一颗" + name() + "。\n", me);

	if((int)me->query_temp("apply_zijindan") > 2)
	{
		write("可能是由于服食药物太多，你觉得一阵头晕脑胀，昏昏沉沉.....\n");
		me->add_temp("apply/dexerity",-3);
		me->unconcious();
	}
	else {
		me->add_temp("apply/dexerity",1);
		me->add_temp("apply_zijindan",1);
		message_vision("$N顿时觉得浑身轻松了许多，步法也比以前轻快了。\n",me);
	}
	destruct(this_object());
	return 1;
}