// Room: /d/xiangyang/wallw8.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "西城头");
	set("long", @LONG
这里是襄阳的西城头。一些宋兵正在城头巡逻，一个牙将正在这儿负
责接受各种守城材料，一些弓箭手正拈弓搭箭紧盯着城下的动静。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"southeast" : __DIR__"walls7",
		"northdown"  : __DIR__"wallw6",
	]));
	set("objects", ([
		__DIR__"npc/ya"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}
