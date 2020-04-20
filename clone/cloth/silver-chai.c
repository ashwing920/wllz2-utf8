// silver-chai.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( HIW "银钗" NOR , ({ "silver chai", "chai" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一支普通的银钗。\n");
                set("unit", "支");
                set("value", 500);
		set("material", "silver");
		set("armor_type", "head");
		set("armor_prop/armor", 1 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N将$n拿出插在头发上。\n");
        }
        setup();
}
