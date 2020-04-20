// zimuzhen.c
#include <weapon.h>
inherit THROWING;

void create()
{
        set_name("子母飞针", ({"zimuzhen", "zhen" }));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一根细若柔丝的银针。\n");
                set("unit", "些");
                set("base_value", 1);
                set("material", "steel");
                set("base_unit", "根");
                set("base_weight", 1); 
        }       
        set_amount(300);
        init_throwing(50);
        setup();
}
