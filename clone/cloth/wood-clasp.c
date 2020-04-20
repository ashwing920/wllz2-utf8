// wood-clasp.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( YEL "木簪" NOR , ({ "wood clasp", "clasp" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一支普通的木簪。\n");
                set("unit", "支");
                set("value", 50);
		set("material", "wood");
		set("armor_type", "head");
		set("armor_prop/armor", 0 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N将$n拿出插在头发上。\n");
        }
        setup();
}
