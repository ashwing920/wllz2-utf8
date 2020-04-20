// Room: /d/fuzhou/nanmen.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "福州南门");
	set("long", @LONG
这里是福州南门。
LONG
);
	set("exits", ([
		"south" : __DIR__"zhongzhou",
		"north" : __DIR__"nanmendou",
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

