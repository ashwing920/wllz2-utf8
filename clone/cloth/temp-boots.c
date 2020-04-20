// boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name(HIC "水晶鞋" NOR, ({ "shuijing xie", "boots" }) );
        set_weight( 400 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一双水晶鞋。\n");
                set("unit", "双");
                set("value", 100);
		set("material", "cloth");
		set("armor_type", "boots");
		set("armor_prop/armor", 2 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 2 );
        }
        setup();
}
