// fish.c 鱼 

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(WHT"罗非"NOR,({"luofei yu","yu","fish"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","一条新鲜的罗非。\n");
		set("unit","条");
		set("value",240);
		set("food_remaining", 3);
		set("food_supply",30);
	}
}
int is_fish() { return 1;}