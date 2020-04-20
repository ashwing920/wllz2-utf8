// snow-silk.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIW "雪白绸裙" NOR, ({ "snow dress", "dress", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一件普通的雪白绸裙。\n");
                set("unit", "件");
                set("value", 1000);
		set("material", "silk");
		set("armor_type", "cloth");
		set("armor_prop/armor", 1 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 3 );
        }
        setup();
}
