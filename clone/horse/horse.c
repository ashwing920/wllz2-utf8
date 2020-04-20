// horse.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM"紫骝马"NOR, ({"ziliu ma","ma","horse" }) );
	set_max_encumbrance(50000);
	set("horse_prop/max_life",20);
	set("horse_prop/life",20);
	set("prep", "on");
	set_weight(0);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "匹");
		set("long", @LONG
这是一匹紫骝马，它可以快速地使你到达某个地方。
LONG
);

	set("value",100000);
    };
}

int is_container() { return 1; }
