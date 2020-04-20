// yin-kui.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( HIW "银盔" NOR , ({ "yin kui", "hat" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一顶普通的银盔。\n");
                set("unit", "顶");
                set("value", 10000);
		set("material", "silver");
		set("armor_type", "head");
		set("armor_prop/armor", 8 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N将$n取出戴在头上。\n");
        }
        setup();
}
