// stone-1.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW"白玉残片"NOR, ({ "baiyu canpian","canpian" }) );
	set_weight(100);
	set("long","一块晶莹剔透的"+ this_object()->query("name")+"。\n");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value",0);
		set("unit","块");
		set("material","diamond");
	};
	setup();
}
