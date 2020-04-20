// jieyao.c 解药

inherit ITEM;

void setup()
{}

void create()
{
	set_name("五毒清心散", ({"qing xinsan", "yao", "qing"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包五毒教的独门解药。\n");
		set("value", 5000);
	}
	setup();
}

int do_use(string arg)
{
	if (!id(arg))
		return notify_fail("你要吃什么药？\n");
	this_player()->apply_condition("wudu_poison",
	this_player()->query_condition("wudu_poison")/20);
	message_vision("$N吃下一包五毒清心散，看起来脸色好多了。\n",this_player());
	destruct(this_object());
}