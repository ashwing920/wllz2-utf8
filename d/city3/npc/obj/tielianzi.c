// tielianzi.c
 
#include <weapon.h>
#include <ansi.h>
inherit THROWING;
 
void create()
{
        set_name(HIW+BLK"铁莲子"NOR, ({ "tie lianzi", "lianzi", "zi" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "精铁打制的莲子状暗器。\n");
                set("unit", "把");
                set("value",100);
                set("base_unit", "粒");
                set("base_weight", 1);
                set("base_value", 0);
                set("material", "iron");
                set("damage", 5);       //Here the damage=int_throwing, added by King
                set("wield_msg", HIC"$N迅速地从暗器袋中掏出一些铁莲子，捏在手中就待发出！\n"NOR);
                set("unwield_msg",HIC"$N将手里剩下的铁莲子尽数放回暗器袋中。\n"NOR);
        }
        set_amount(30);
        init_throwing(5);
        setup();
}
