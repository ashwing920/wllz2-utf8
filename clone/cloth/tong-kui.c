// tong-kui.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( YEL "铜盔" NOR , ({ "tong kui", "hat" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一顶普通的铜盔。\n");
                set("unit", "顶");
                set("value", 8000);
		set("material", "corpper");
		set("armor_type", "head");
		set("armor_prop/armor", 7 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N将$n取出戴在头上。\n");
        }
        setup();
}
