// horse.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"追风马"NOR, ({ "zhuifeng ma","ma","horse" }) );
	set_max_encumbrance(400000);
        set("horse_prop/max_life",70);
        set("horse_prop/life",70);
        set("prep", "on");
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "匹");
                set("long", @LONG
这是一匹追风马，它可以快速地使你到达某个地方。
LONG
);

	set("value",800000);
    };
}

int is_container() { return 1; }
