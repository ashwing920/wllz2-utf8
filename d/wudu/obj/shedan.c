// 普通蛇胆 shedan

inherit ITEM;

void create()
{
	set_name("蛇胆", ({"she dan", "dan"}));
	set("unit", "只");
	set("long", "这是一只蛇胆。\n");
	set("value", 100);
	setup();
}

