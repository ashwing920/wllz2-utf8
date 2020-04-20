//Cracked by Kafei
// yangxin.c 养心丸

inherit ITEM;

#include <ansi.h>

void setup()
{}

int cure_ob(string);

void create()
{
	set_name("养心丸", ({"yangxin wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗暗红发亮的养心丸。\n");
		set("value", 5000);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	message_vision(HIR "$N吃下一棵养心丹，只觉得头重脚轻，火气翻腾，原来服食过猛，药效适得其反！\n" NOR, this_player());
	this_player()->add("jingli", -200);
	this_player()->apply_condition("bonze_drug", 
		this_player()->query_condition("bonze_drug")+10);
	destruct(this_object());
	return 1;
}
