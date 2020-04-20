// xiaochao-boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("粉底小朝靴", ({ "xiao chaoxue", "boots" }) );
        set_weight( 1000 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一双粉底小朝靴。\n");
                set("unit", "双");
                set("value", 12000);
		set("material", "cloth");
		set("armor_type", "boots");
		set("armor_prop/armor", 3 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 2 );
        }
        setup();
}
