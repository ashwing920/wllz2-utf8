// dahong-jiasha.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIR "大红袈裟" NOR, ({ "dahong jiasha", "jiasha", "cloth" }) ); 
	set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "这是一件大红袈裟。\n");
                set("unit", "件");
                set("value", 10000);
		set("material", "silk");
		set("armor_type", "cloth");
		set("armor_prop/armor", 1 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 5 );
        }
        setup();
}
