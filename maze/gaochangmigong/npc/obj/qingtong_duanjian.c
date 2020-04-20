// sword.c 剑

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(CYN"青铜短剑"NOR, ({ "qingtong duanjian","duanjian","sword" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit","柄");
                set("long","这是一柄青铜冶炼的短剑，剑身青光闪闪，十分耀眼。\n");
                set("value",3500);
                set("material","steel");
                set("wield_msg","$N「唰」的一声拔出一柄$n握在手中。\n");
                set("unwield_msg","$N将手中的$n插回剑鞘。\n");
        }
        init_sword(225);
        setup();
}
