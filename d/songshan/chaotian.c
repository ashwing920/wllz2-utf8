// Room: /d/songshan/chaotian.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "朝天门");
	set("long", @LONG
陡见双峰中断，天然出现一个门户，疾风从断绝处吹出，云雾随风扑
面而至，这里就是朝天门了。
LONG
);
	set("exits", ([
		"northup"   : __DIR__"shandao6",
		"southdown" : __DIR__"shandao5",
	]));
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

