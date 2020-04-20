// xiaozhan-boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("五彩小战靴", ({ "xiao zhanxue", "boots" }) );
        set_weight( 1000 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一双五彩颜色的小战靴。\n");
                set("unit", "双");
                set("value", 6000);
		set("material", "cloth");
		set("armor_type", "boots");
		set("armor_prop/armor", 8 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 2 );
        }
        setup();
}
