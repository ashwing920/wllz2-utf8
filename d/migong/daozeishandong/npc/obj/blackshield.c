// tou-kui.c

#include <ansi.h>
#include <armor.h>

inherit SHIELD;

void create()
{
        set_name(HIK"黑色披风"NOR, ({ "pifeng","shield" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一条黑色的披风。\n");
                set("unit", "条");
                set("value", 1000);
		set("material","cloth");
		set("armor_type","shield");
		set("armor_prop/armor",80);
        	set("wear_msg", "$N将$n披在肩上绑好。\n");
		set("remove_msg","$N将肩膀上的$n解了下来。\n");
        }
        setup();
}
