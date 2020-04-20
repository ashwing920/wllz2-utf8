//Cracked by Kafei

#include <ansi.h>

inherit ITEM;

int cure_ob(string);

void create()
{
	set_name(RED"八宝红灵丹"NOR, ({"babao honglingdan","babao dan","dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("value", 2000);
		set("long", "这是一颗可以让恢复精力的八宝红灵丹。\n");
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	message_vision("$N吃下一颗" + name() + "。\n", me);

	if((int)me->query("jingli") >= (int)me->query("max_jingli"))
	{
		write("不过你觉得好像什么用也没有。\n");
	}
	else {
		me->add("jingli",(int)me->query("max_jingli") / 10);
		message_vision("$N顿时觉得精力充沛，精神活跃。\n",me);
	}
	destruct(this_object());
	return 1;
}