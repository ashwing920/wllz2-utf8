// duxiefeng.c 毒蝎粉

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(RED"毒蝎粉"NOR, ({"duxie feng","feng"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","一堆红褐色的毒蝎粉，可以服用。\n");
		set("unit","堆");
		set("value",1000);
	}
	setup();
}

void init()
{
	if(environment() == this_player())
	add_action("do_eat","eat");
}
int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("你要吃什么？\n");

	if(!me->query_condition("duxie_poison")){ 
		message_vision("$N拿起毒蝎粉，往身上撒了上去，顿觉浑身痕痒，十分难受。\n",me);
		me->apply_condition("duxie_poison",30);
	}
	else{
		me->apply_condition("duxie_poison",me->query_condition("duxie_poison") - 20);
		tell_object(me,"你服下毒蝎粉，顿时觉得身上的痕痒好像好多了。\n");
	}
	destruct(this_object());
	return 1;
}
