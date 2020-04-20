
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR "断肠花" NOR, ({"hua3","duanchang"}));
	set_weight(100);
	if( clonep() )
	       set_default_object(__FILE__);
	else {
		set("unit","朵");
		set("long","这是一朵断肠花,通体通红,鲜嫩欲滴,美丽异常。\n");
		set("value",0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg)) 
		return notify_fail("你要吃什么？\n");

	if(random(2)==0) 
		this_player()->unconcious();
	else 
		this_player()->die();

	destruct(this_object());
	return 1;
}
