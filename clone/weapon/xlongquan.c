// tielianzi.c
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(HIC"小龙泉"NOR, ({ "xiao longquan","longquan" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {

                set("unit", "些");
                set("value",500);
                set("base_unit", "柄");
                set("base_weight", 300);
                set("base_value",5);
                set("material", "iron");
                set("long", "这是一柄小龙泉，通常被因为短小且杀伤力大，通常被做暗器使用。\n");
                set("wield_msg", "$N摸出一把小龙泉，夹在手中就待发出！\n"NOR);
                set("unwield_msg","$N将手里剩下的小龙泉放进衣兜中。\n"NOR);
        }
        set_amount(100);
        init_throwing(100);
        setup();
}
