// horse.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"烈日马"NOR, ({ "lieri ma","ma","horse" }) );
	set_max_encumbrance(300000);
        set("horse_prop/max_life",60);
        set("horse_prop/life",60);
        set("prep", "on");
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "匹");
                set("long", @LONG
这是一匹烈日马，它可以快速地使你到达某个地方。
LONG
);

	set("value",600000);
    };
}

int is_container() { return 1; }
