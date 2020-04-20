// wood_blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("木刀", ({ "wood blade", "blade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 500);
                set("material", "wood");
                set("long", "这是一把练习刀法用的木刀。\n");
                set("wield_msg", "$N拿出一把练刀用的$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_blade(8);
        setup();
}
 
