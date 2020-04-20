// sword.c 剑

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIM"紫金"HIY"八卦刀"NOR, ({ "zijin baguadao","blade","baguadao" }));
        set_weight(25000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit","把");
		set("long","一把无坚不摧的紫金八卦刀，刀身泛着一阵幽幽的光芒，刀把上刻着一个阴阳太极的符号。\n");
                set("value",3500);
                set("material","steel");
                set("rigidity",2);
                set("wield_msg","$N「唰」的一声拔出一柄$n握在手中。\n");
                set("unwield_msg","$N将手中的$n插回刀鞘。\n");
        }
        init_blade(635);
        setup();
}
