// horse.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"黄骠马"NOR, ({ "huangpiao ma","ma","horse" }) );
	set_max_encumbrance(200000);
        set("horse_prop/max_life",40);
        set("horse_prop/life",40);
        set("prep", "on");
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "匹");
                set("long", @LONG
这是一匹黄骠马，它可以快速地使你到达某个地方。
LONG
);

	set("value",400000);
    };
}

int is_container() { return 1; }
