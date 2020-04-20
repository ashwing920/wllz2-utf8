// huayuan.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","后院");
	set("long",@LONG
这是僻静的后院，住着欧阳克的老奶妈张妈。由于年岁已高，她已经
不干活了，在这里静养。
LONG
);
	set("exits",([
		"southeast" : __DIR__"zhuyuan",
	]));
	set("outdoors", "baituo");
	set("objects",([
		__DIR__"npc/zhangma" : 1,
	]));
	setup();
	replace_program(ROOM);
}






