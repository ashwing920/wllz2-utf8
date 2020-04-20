// yangxin.c 理气丸

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY"理气丸"NOR, ({"liqi wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗由回春堂出售的理气丸，据说可以调整内息，安定气息的作用。\n");
		set("value", 3000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if(!id(arg))
		return notify_fail("你要吃什么？\n");

	message_vision("$N一仰脖，吃下一颗理气丸。\n", me);
	
	if(me->query_condition("ill_dongshang")){
		me->apply_condition("ill_dongshang",0);
		tell_object(me,HIW"你觉得全身上下暖和了许多，体内的寒气也逐渐消失了。\n"NOR);
	}
	else if(me->query_condition("ill_kesou")){
		me->apply_condition("ill_kesou",0);
		tell_object(me,HIY"你觉得肺部十分清凉，咳嗽的症状也逐渐消失了。\n"NOR);
	}
	else if(me->query_condition("ill_zhongshu")){
		me->apply_condition("ill_zhongshu",0);
		tell_object(me,HIW"你全身开始冒汗，体内的暑气也逐渐退散了。\n"NOR);
	}
	else if(me->query_condition("ill_shanghan")){
		me->apply_condition("ill_shanghan",0);
		tell_object(me,HIW"你觉得身上的逐渐暖和，伤寒之气也逐渐消失了。\n"NOR);
	}
	else if(me->query_condition("ill_fashao")){
		me->apply_condition("ill_fashao",0);
		tell_object(me,HIW"你觉得额头的热气逐渐消散，人也精神了许多。\n"NOR);
	}
	else {
		me->apply_condition("ill_duzitong",30);
		tell_object(me,HIG"你觉得肚中一阵真气搅动，接着什么感觉也没有了。\n"NOR);
	}
	destruct(this_object());
	return 1;
}
