// gold-chai.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( HIY "金钗" NOR , ({ "gold chai", "chai" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一支普通的金钗。\n");
                set("unit", "支");
                set("value", 5000);
		set("material", "gold");
		set("armor_type", "head");
		set("armor_prop/armor", 2 );
		// set("armor_prop/defense", 0 );
                // set("armor_prop/dodge", 0 );
        	set("wear_msg", "$N将$n拿出插在头发上。\n");
        }
        setup();
}
