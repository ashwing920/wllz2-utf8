// xiaolu1.c 林间小径
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "林间小径");
	set("long", @LONG
你走在一条小径上，两旁种满了竹子，修篁森森，绿荫满地，除了竹
叶声和鸟鸣声，听不到别的动静。
LONG
);
	set("exits", ([
		"south" : __DIR__"xiaolu2",
		"north" : __DIR__"houyuan",
	]));
	set("outdoors", "wudang");
	setup();
}
