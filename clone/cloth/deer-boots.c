// deer-boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("鹿皮小靴", ({ "deer boots", "boots" }) );
        set_weight( 1000 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一双鹿皮做的靴子。\n");
                set("unit", "双");
                set("value", 2000);
		set("material", "cloth");
		set("armor_type", "boots");
		set("armor_prop/armor", 4 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 1 );
        }
        setup();
}
