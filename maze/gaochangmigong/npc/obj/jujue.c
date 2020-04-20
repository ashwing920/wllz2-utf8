// sword.c 剑

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIC"巨厥"NOR, ({ "ju jue","jian","sword" }));
        set_weight(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit","柄");
                set("long","上等的兵器“巨厥”，剑身坚硬，剑锋锋芒闪闪，一看就知道是一把削铁如泥的好剑。\n");
                set("value",3500);
                set("material","steel");
                set("rigidity",2);
                set("wield_msg","$N「唰」的一声拔出一柄$n握在手中。\n");
                set("unwield_msg","$N将手中的$n插回剑鞘。\n");
        }
        init_sword(425);
        setup();
}
