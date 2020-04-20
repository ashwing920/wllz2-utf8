// houhuayuan.c 后花园
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "后花园");
	set("long", @LONG
这里是一个小花园，杂乱地种着各种花草，看来无人打理，杂草已经
长得很高了。有一些红的，白的鲜花夹杂在草丛中，阵阵花香不断地飘过
。东面有一道小门，南面是一座两层小楼。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([
		"northwest" : __DIR__"fu-houyuan",
		"south" : __DIR__"guanjinglou",
		"east" : __DIR__"houhuayuan1",
	]));
	setup();
	replace_program(ROOM);
}
