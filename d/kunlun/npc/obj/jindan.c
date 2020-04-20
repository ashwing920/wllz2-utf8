// by mei

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name("金冠蛇胆", ({"jin dan", "dan"}));
	set("unit", "颗");
	set("long", "这是一颗红冬冬的金冠蛇胆。\n");
	set("value", 100);
	setup();
}
int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");
	this_player()->set("eff_qi", this_player()->query("max_qi"));
	this_player()->set("eff_jing", this_player()->query("max_jing"));
		message_vision("$N服下一颗金冠蛇胆,顿觉精力百倍！\n", this_player());
	destruct(this_object());
	return 1;
}
