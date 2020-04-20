// cao-hat.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( "草帽" , ({ "cao mao", "hat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一顶普通的草帽。\n");
                set("unit", "顶");
                set("value", 50);
		set("material", "grass");
		set("armor_type", "head");
		set("armor_prop/armor", 1 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N将$n取出戴在头上。\n");
        }
        setup();
}
