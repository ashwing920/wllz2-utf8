//chi2.c 寒冰池内
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short","寒冰池内");
	set("long",@LONG
这里是寒冰池下，四周倒还渐渐有些昏暗了，几道天光从头顶的潭水
中投射下，此时也不那么瑰丽了，昏沉沉的犹如天边的晚霞。脚下漆黑一
片也不知有些什么。四周的水流也没有那么平静了，似乎在向一个方向流
动着。
LONG
);
	set("exits", ([
		"south" : __DIR__"chi2",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();

	tell_object(me,HIG"一股寒气袭上心头，你快被冻僵了！牙齿开始格格做响！\n"NOR);
	if((int)me->query_skill("force", 1) > 120 && (int)me->query("neili") > 5000 )
{
	me->improve_skill("force", random(me->query("int")));
	me->receive_damage("jing",random(10));
	me->add("neili",- 100);
	tell_object(me,"你运足内力与冰冷的池水相对抗，似乎觉得身体要暖和了些。\n");
	tell_object(me,HIC"你的精气消耗了些许，但内力好象有所提高了！\n"NOR);
}
	else {
	this_player()->receive_damage("jing",10 + random(20));
	tell_object(me,HIR"你的精气开始消耗了！\n"NOR);
	}

}
