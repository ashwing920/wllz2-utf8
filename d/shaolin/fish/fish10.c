// fish.c 鱼 

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(WHT"小鱼儿"NOR,({"xiaoyu er","yu","fish"}));
	set_weight(30);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","一条新鲜的小鱼儿。\n");
		set("unit","条");
		set("value",100);
		set("food_remaining", 3);
		set("food_supply",30);
	}
}
int is_fish() { return 1;}