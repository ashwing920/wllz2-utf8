// huwan.c 护腕

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
        set_name(HIR"愤击护手"NOR, ({ "power wrists", "hu shou", "hushou" }) );
        set_weight(25500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", @LONG
一双青铜打造的护手，能够对手部起到一定的保护作用，并可以用来攻击
对手，可惜十分沉重。
LONG
);
                set("value", 2500);
                set("material","icon");
                set("armor_prop/armor",105);
                set("armor_prop/unarmed_damage",225);
                set("wear_msg","$N套上一双愤击护手。\n");
                set("remove_msg","$N将愤击护手从手上脱了下来。\n");
        }
        setup();
}
