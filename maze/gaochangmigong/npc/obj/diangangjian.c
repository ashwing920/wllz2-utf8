// sword.c 剑

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIM"点钢血剑"NOR, ({ "diangang jian","jian","sword" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit","柄");
                set("long","这是一柄精打细琢，经过千锤百炼的长剑，剑尖还残留着一丝血色。\n");
                set("value",4500);
                set("material","steel");
                set("wield_msg","$N「唰」的一声拔出一柄$n握在手中。\n");
                set("unwield_msg","$N将手中的$n插回剑鞘。\n");
        }
        init_sword(255);
        setup();
}
