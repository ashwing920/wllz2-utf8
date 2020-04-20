// iron-baojia.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( WHT "铁铠宝甲" NOR, ({ "tiekai baojia", "baojia" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "这是一件铁铠宝甲。\n");
                set("unit", "件");
                set("value", 15000);
		set("material", "iron");
		set("armor_type", "cloth");
		set("armor_prop/armor", 10 );
		// set("armor_prop/defense", 10 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
