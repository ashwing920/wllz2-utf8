// zhan-boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("战靴", ({ "zhan xue", "boots" }) );
        set_weight( 1500 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一双普通的战靴。\n");
                set("unit", "双");
                set("value", 5000);
		set("material", "cloth");
		set("armor_type", "boots");
		set("armor_prop/armor", 10 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
