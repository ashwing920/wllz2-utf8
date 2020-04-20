//Cracked by Kafei

#include <ansi.h>

inherit ITEM;

void setup()
{}

void create()
{
	set_name(HIK"黑玉断续膏"NOR, ({"heiyu duanxugao","heiyu","duanxugao","gao"}));
	set_weight(50);
	if (clonep())
	set_default_object(__FILE__);
	else 
		{
		set("unit", "颗");
		set("long", "黑黑的一颗药丸，此乃罕见的疗伤圣药黑玉断续膏。\n");
		set("value", 0);
		set("medicine", 1);
	}
	setup();
}
