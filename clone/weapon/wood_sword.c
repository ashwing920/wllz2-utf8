// wood_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("木剑", ({ "wood sword", "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把用木头做成的剑，剑尖是锐圆的以免误伤同伴。\n");
                set("value", 500);
                set("material", "bamboo");
                set("wield_msg", "$N拿出一把练剑用的$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_sword(8);
        setup();
}
 
