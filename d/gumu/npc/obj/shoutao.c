// huwan.c 护腕

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
        set_name(HIC"天蚕丝手套"NOR, ({ "shou tao","shoutao"}) );
        set_weight(25500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", @LONG
一双蚕丝编织而成的手套，柔软舒适，是古墓新派弟子练功的好东西。
LONG
);
                set("value", 1250);
                set("material","icon");
                set("armor_prop/armor",75);
                set("armor_prop/unarmed_damage",95);
                set("wear_msg","$N套上一双天蚕丝手套。\n");
                set("remove_msg","$N将天蚕丝手套从手上脱了下来。\n");
        }
        setup();
}
