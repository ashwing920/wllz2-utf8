// silver-baojia.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIW "银铠宝甲" NOR, ({ "yinkai baojia", "baojia" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "这是一件银铠宝甲。\n");
                set("unit", "件");
                set("value", 30000);
		set("material", "silver");
		set("armor_type", "cloth");
		set("armor_prop/armor", 30 );
		// set("armor_prop/defense", 20 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
