// xiaoyao-jin.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( "逍遥巾" , ({ "xiaoyao jin", "hat" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一顶普通的逍遥巾。\n");
                set("unit", "顶");
                set("value", 100);
		set("material", "cloth");
		set("armor_type", "head");
		set("armor_prop/armor", 0 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N将$n取出戴在头上。\n");
        }
        setup();
}
