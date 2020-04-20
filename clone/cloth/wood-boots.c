// wood-boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("木屐", ({ "mu ji", "boots" }) );
        set_weight( 500 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一双木头做的木屐。\n");
                set("unit", "双");
                set("value", 100);
		set("material", "wood");
		set("armor_type", "boots");
		set("armor_prop/armor", 2 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
