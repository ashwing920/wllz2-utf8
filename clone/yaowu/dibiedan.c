//Cracked by Kafei

#include <ansi.h>

inherit ITEM;

int cure_ob(string);

void create()
{
	set_name(YEL"地鱉"HIY"紫金丹"NOR, ({"dibie zijindan","dibie dan","dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("value", 1500);
		set("long", "这是一颗地鱉紫金丹，服食以后可以让人功力大增。\n");
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	message_vision("$N吃下一颗" + name() + "。\n", me);

	if((int)me->query_temp("apply_dibiedan") > 2)
	{
		write("可能是由于服食药物太多，你觉得一阵头晕脑胀，昏昏沉沉.....\n");
		me->add_temp("apply/strength",-3);
		me->unconcious();
	}
	else {
		me->add_temp("apply/strength",1);
		me->add_temp("apply_dibiedan",1);
		message_vision("$N猛吸了一口气，看起来好像充满了力量。\n",me);
	}
	destruct(this_object());
	return 1;
}