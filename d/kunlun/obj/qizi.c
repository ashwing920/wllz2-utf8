//qizi.c 

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
        set_name(HIW "棋子" NOR , ({ "qi zi","qi" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是一把围棋子。\n");
                set("unit", "把");
                set("base_unit", "枚");
                set("base_weight", 1);
                set("base_value", 10);
        }
                set_amount(100);
                init_throwing(5);
                setup();
}
