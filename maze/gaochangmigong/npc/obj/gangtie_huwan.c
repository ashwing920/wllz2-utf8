// huwan.c 护腕

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
        set_name(WHT"钢铁护腕"NOR, ({ "wrists", "hu wan", "huwan" }) );
        set_weight(10500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long", "这是一件铁铸的护腕，看起来十分沉重。\n");
                set("value", 1300);
                set("material","icon");
                set("armor_prop/armor",105);
        }
        setup();
}
