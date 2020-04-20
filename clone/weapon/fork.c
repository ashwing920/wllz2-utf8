// fork.c 钢叉

#include <weapon.h>

inherit FORK;

void create()
{
        set_name("钢叉", ({ "fork" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "这是一支普通的钢叉。\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声拔出一支$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_fork(25);
        setup();
}
