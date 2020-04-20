// cao-boots.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("草鞋", ({ "cao xie", "boots" }) );
        set_weight( 300 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一双普通的草鞋。\n");
                set("unit", "双");
                set("value", 50);
		set("material", "grass");
		set("armor_type", "boots");
		set("armor_prop/armor", 0 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 1 );
        }
        setup();
}
