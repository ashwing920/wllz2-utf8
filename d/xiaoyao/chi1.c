//chi1.c 寒冰池内
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short","寒冰池内");
	set("long",@LONG
这里是寒冰池内，四周倒还比较明亮，几道天光从头顶的池水中投射
下来，显得十分美丽。脚下漆黑一片也不知有些什么。你不禁全身颤抖，
双腿发软。
LONG
);
	set("exits", ([
		"up" : __DIR__"hanbingchi",
		"down" : __DIR__"chi2",
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
