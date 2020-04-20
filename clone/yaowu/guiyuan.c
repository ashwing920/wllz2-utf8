//Cracked by Kafei
// guiyuan.c 归元丹

inherit ITEM;

#include <ansi.h>

void setup()
{}

int worn;

int cure_ob(string);
void create()
{
	set_name("归元丹", ({"guiyuan dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗莹白溜圆的归元丹。\n");
		set("value", 5000);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	this_player()->add("neili", -200);
	message_vision(HIR "$N吃下一棵归元丹，只觉得头重脚轻，火气翻腾，原来服食过猛，药效适得其反！\n" NOR, this_player());
	this_player()->apply_condition("bonze_drug",this_player()->query_condition("bonze_drug")+10);
	destruct(this_object());
	return 1;
}
