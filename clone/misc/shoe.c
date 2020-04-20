// boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	 set_name( "靴子" , ({ "boots" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		 set("long", "一双靴子。\n");
		set("value", 0);
		set("material", "boots");
		set("armor_prop/dodge", 1);
	}
	setup();
}

