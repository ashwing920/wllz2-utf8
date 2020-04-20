
// blade.c
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("削刀", ({ "xuemu dao","dao"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
                set("value",1000);
                set("material","iron");
                set("long", "这是一把削木头用的削刀。\n");
                set("wield_msg", "$N拿出一把$n握在手中准备战斗。\n");
                set("unwield_msg", "$N将手中的$n小心放好。\n");
        }
        init_blade(2);
        setup();
}
