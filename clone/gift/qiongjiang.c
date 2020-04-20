// qiongjiang.c 琼浆

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC"琼浆"NOR, ({"qiong jiang", "jiang",}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一瓶晶莹透亮的琼浆，喝(drink)下去好像有特别的效果。\n");
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
	if (me->query("gift/qiongjiang") >= 5){
		message_vision("$N打了个响嗝，看起来好像很舒畅。\n", me);
		tell_object(me,"你发现竟然什么用也没有。\n");
	} else
	if (random(5) == 0){
		tell_object(me, "不过你觉得好像没什么作用。\n");
	} else{
		message("vision", me->name() + "突然怒发冲冠，一缕清烟从头上徐徐升起。\n",environment(me), ({ me }));
		tell_object(me, HIC"你眼前一亮，突然觉得脑子里特别的清醒。\n" NOR);
		me->add("spi", 1);
	}
	me->add("gift/qiongjiang", 1);
	destruct(this_object());
	return 1;
}

