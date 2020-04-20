// tou-kui.c

#include <ansi.h>
#include <armor.h>

inherit SHIELD;

void create()
{
        set_name(CYN"流云披风"NOR, ({ "liuyun pifeng","shield" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一件灰蓝色的披风，一般只有侠客才披着这样的披风。\n");
                set("unit", "件");
                set("value", 1000);
                set("material","cloth");
                set("armor_type","shield");
                set("armor_prop/armor",100);
                set("wear_msg", "$N将$n披在肩上绑好。\n");
                set("remove_msg","$N将肩膀上的$n解了下来。\n");
        }
        setup();
}
