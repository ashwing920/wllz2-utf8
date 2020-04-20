// gua-cloth.c 

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name( "布褂", ({ "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一件普通的布褂。\n");
                set("unit", "件");
                set("value", 50);
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor", 1 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        }
        setup();
}
