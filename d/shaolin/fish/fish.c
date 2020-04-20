// fish.c 鱼 

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIR"红鳟鱼"NOR,({"hongzun yu","yu","fish"}));
	set_weight(120);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","一条新鲜的红鳟鱼。\n");
		set("unit","条");
		set("value",130);
		set("food_remaining", 3);
		set("food_supply",30);
	}
}
int is_fish() { return 1;}