// food.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("食物", ({"food"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "还没定义，给下层调用。\n");
		set("unit", "盘");
		set("value", 40);
		set("no_put",1);
		set("no_sell",1);
		set("no_pawn",1);
		set("is_order_food",1);
		set("food_remaining", 5);
		set("food_supply", 15);
	}
}
