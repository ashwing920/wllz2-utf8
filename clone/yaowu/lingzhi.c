// lingzhi.c 千年灵芝

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("千年灵芝", ({"ling zhi","zhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵千年灵芝，据说可以补气解毒的作用。\n");
		set("value", 100000);
		set("weight", 100);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("你要吃什么？\n");
		
	this_player()->receive_curing("qi", 100);
	message_vision("$N吃下一棵千年灵芝，顿时间觉得全身充满了活力！\n", this_player());
	if(this_player()->query_condition("sanyin_poison")) {
		this_player()->apply_condition("sanyin_poison",0);
		tell_object(this_player(),"你解除了“三阴掌”中毒状态。\n");
	}
	this_player()->set("eff_qi",this_player()->query("max_qi"));
	this_player()->set("qi",this_player()->query("eff_qi"));
	tell_object(this_player(),"你的气血恢复了。\n");
	destruct(this_object());
	return 1;
}