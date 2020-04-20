// staff.c 铁杖

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("铁棒", ({ "staff" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根普通的铁棒。\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg", "$N「唰」的一声拔出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_staff(25);
        setup();
}
