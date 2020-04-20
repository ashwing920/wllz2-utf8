// tou-kui.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( "头盔" , ({ "tou kui", "hat" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一顶普通的头盔。\n");
                set("unit", "顶");
                set("value", 1000);
		set("material", "bamboo");
		set("armor_type", "head");
		set("armor_prop/armor", 5 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N将$n取出戴在头上。\n");
        }
        setup();
}
