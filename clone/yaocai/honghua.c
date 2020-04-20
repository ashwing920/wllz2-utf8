// honghua.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"红花"NOR, ({ "hong hua", "hong", "hua" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵红花，不过看起来好象没什么用。\n");
		set("value", 30);
		set("material", "grass");
	}
	setup();
}
int is_yaocai() { return 1;}
