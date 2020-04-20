// jiangfu.c 施琅将军府
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "将军府");
	set("long", @LONG
这是靖海侯府的书房，里面除了书籍之外，更多的还是各种兵刃。
LONG
);
	set("exits", ([
		"south" : __DIR__"jiangfu",
	]));
	set("objects", ([
		__DIR__"npc/shilang" : 1,
	]));
	setup();
	replace_program(ROOM);

}
