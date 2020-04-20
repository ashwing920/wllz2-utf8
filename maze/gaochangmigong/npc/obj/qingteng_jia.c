// cloth.c example cloth

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIG"青藤甲"NOR, ({ "qingteng jia","jia"}) );
        set_weight(18000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","一件用青藤编织而成的盔甲。\n");
		set("unit","件");
                set("value",10000);
                set("material","bomboo");
                set("armor_type","cloth");
                set("armor_prop/personality",-8);
                set("armor_prop/armor",250);
                set("wear_msg","$N穿上一件$n。\n");
                set("remove_msg","$N将$n脱了下来。\n");
        }
        setup();
}
