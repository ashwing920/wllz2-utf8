// tou-kui.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIK"盗贼头巾"NOR, ({ "tou jin","hat" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一条黑色的盗贼头巾。\n");
                set("unit", "条");
                set("value", 1000);
		set("material","cloth");
		set("armor_type", "head");
		set("armor_prop/armor",50);
        	set("wear_msg", "$N将$n取出戴在头上。\n");
        }
        setup();
}
