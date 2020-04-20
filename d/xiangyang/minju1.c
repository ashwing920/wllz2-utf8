// Room: /d/xiangyang/minju1.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这是一家比较有钱人的住房，房子主人正在家里忙这忙那，看见你进
来，急忙站起身向你打招呼。
LONG
);
	set("exits", ([
		"west" : __DIR__"jiedao",
	]));
	setup();
	replace_program(ROOM);
}

