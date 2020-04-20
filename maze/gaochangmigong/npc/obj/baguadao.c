// sword.c 剑

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIW"八卦刀"NOR, ({ "bagua dao","dao","blade" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit","把");
                set("long","一把削铁如泥的八卦刀，刀把上刻着一个阴阳太极的符号。\n");
                set("value",5000);
                set("material","steel");
                set("wield_msg","$N「唰」的一声拔出一柄$n握在手中。\n");
                set("unwield_msg","$N将手中的$n插回刀鞘。\n");
        }
        init_blade(285);
        setup();
}
