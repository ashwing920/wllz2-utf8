// suo-cloth.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( "蓑衣", ({ "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一件普通的蓑衣。\n");
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
