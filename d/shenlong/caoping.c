// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "草坪");
	set("long", @LONG
这里是一片青青的草坪，有几个少年在玩耍。四周开满了各色的鲜花
，一阵凉风吹过，清新的空气中传来几缕淡淡的花香。
LONG
);
	set("exits", ([
		"east" : __DIR__"kongdi",
	]));
	set("objects", ([
		"/d/center/npc/boy": 2,
		"/d/center/npc/girl": 2,
		__DIR__"obj/hua":1,
		__DIR__"obj/hua2": random(2)+1,
		__DIR__"obj/hua3": random(3)+1,
		__DIR__"obj/hua4": random(3)+1,
	]));
	set("outdoors", "shenlong");
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("duanchang", environment(me)))) {
		if((int)this_player()->query_condition("flower_poison") < 10 ) {
			this_player()->apply_condition("flower_poison", 30);
			tell_object(me, HIG "你只觉一股淡香袭来,顿时脑中一阵麻木！\n" NOR );
		}
	}
	return ::valid_leave(me, dir);
}
