// fish.c 鱼 

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIR"大红鲤鱼"NOR,({"dahong liyu","yu","fish"}));
	set_weight(60);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","一条新鲜的大红鲤鱼。\n");
		set("unit","条");
		set("value",280);
		set("food_remaining", 3);
		set("food_supply",30);
	}
}
int is_fish() { return 1;}