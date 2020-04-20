// fish.c 鱼 

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIM"鲇鱼"NOR,({"nian yu","yu","fish"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","一条新鲜的鲇鱼。\n");
		set("unit","条");
		set("value",150);
		set("food_remaining", 3);
		set("food_supply",30);
	}
}
int is_fish() { return 1;}