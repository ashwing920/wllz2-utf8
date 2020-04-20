// mian.c 面汤

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("饺子", ({"jiao zi", "jiao"}));
	set_weight(60);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("long", "一碗热腾腾的饺子，一股清香扑鼻而来。\n");
		set("unit", "碗");
		set("value", 50);
		set("food_remaining", 6);
		set("food_supply", 120);
		set("eat_msg","$N拿起一碗面汤，狼吞虎咽的吃了起来。\n");
	}
}


