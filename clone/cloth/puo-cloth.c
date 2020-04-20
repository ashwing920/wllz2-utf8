// puo-cloth.c 

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name( "破衣", ({ "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一件普通的破旧衣服。\n");
                set("unit", "件");
                set("value", 0);
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor", 1 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        }
        setup();
}
