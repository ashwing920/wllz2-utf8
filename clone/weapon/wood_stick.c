// wood_sword.c

#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("木棍", ({ "wood club", "club" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把用木头做成的木棍。\n");
                set("value", 500);
                set("material", "wood");
                set("wield_msg", "$N拿出一把练棍用的$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_club(8);
        setup();
}
 
