// yuye.c 玉液

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW"玉液"NOR, ({"yu ye","ye",}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一瓶晶莹透亮的玉液，喝(drink)下去好像有特别的效果。\n");
		set("value", 10000);
		set("unit", "瓶");
	}
}

void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	object me;

	if (!id(arg))
		return notify_fail("你要喝什么？\n");

	me = this_player();
	
	message_vision("$N举起"+ this_object()->name() +"，三两口就喝了个精光。\n", me);
	if (me->query("gift/yuye") >= 5){
		message_vision("$N打了个响嗝，拍拍涨得圆圆的肚子。\n", me);
		tell_object(me,"你发现竟然什么用也没有。\n");
	} else
	if (random(5) == 0){
		tell_object(me, "不过你觉得好像没什么作用。\n");
	} else{
		message("vision", me->name() + "脸上突然泛起一道红光，眼前的一切好像都是那么美好。\n",environment(me), ({ me }));
		tell_object(me, HIC"一阵无名的喜悦涌上心头，你心里总觉得有一股说不出的愉快。\n" NOR);
		me->add("kar", 1);
	}
	me->add("gift/yuye", 1);
	destruct(this_object());
	return 1;
}

