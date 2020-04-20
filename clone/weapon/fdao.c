// tielianzi.c
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(HIW"飞刀"NOR, ({ "fei dao","dao" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {

                set("unit", "些");
                set("value", 100);
                set("base_unit", "把");
                set("base_weight", 300);
                set("base_value",30);
                set("material", "iron");
                set("long", "这是暗器的一种，小飞刀。\n");
                set("wield_msg", "$N摸出一把飞刀，夹在手中就待发出！\n"NOR);
                set("unwield_msg","$N将手里剩下的飞刀镖放进衣兜中。\n"NOR);
        }
        set_amount(50);
        init_throwing(30);
        setup();
}
