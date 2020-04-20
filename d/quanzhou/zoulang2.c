// Room: zoulang2.c 走廊２
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
走廊两旁都有矮墙，将后院间隔起来。北边是「暗器部」，可在那里
学暗器手法。南院是「剑部」，可学剑法。西边则是一间休息室。西北边
传来阵阵香气，必定是厨房所在。西北矮墙旁有口井。
LONG
);

	set("exits", ([
		"north" : __DIR__"anqibu",
		"south" : __DIR__"jianbu",
		"east" : __DIR__"zoulang1",
		"west" : __DIR__"xiuxishi",
		"northwest" : __DIR__"chufang",
	]));
	set("resource/water", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("mark/马") && dir == "west" )
		return notify_fail("你非武馆里的人物，不能住在这里！\n");

	return ::valid_leave(me, dir);
}
