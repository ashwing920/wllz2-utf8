// bamboo_blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("竹刀", ({ "bamboo blade", "blade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 500);
                set("material", "bamboo");
                set("long", "这是一把用扁平青竹片做成的竹刀。\n");
                set("wield_msg", "$N拿出一把练刀用的$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_blade(10);
        setup();
}
 
