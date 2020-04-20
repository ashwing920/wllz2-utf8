// cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("布衣", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","一件用普通布料缝制而成的布衣。\n");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("wear_msg","$N穿上一件$n。\n");
		set("remove_msg","$N将$n脱了下来。\n");
	}
	setup();
}
