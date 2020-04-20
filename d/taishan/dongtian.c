// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "东天门");
	set("long", @LONG
这里是岱顶的东面出口。往东依次经过伏虎门峡口、鹰愁涧等，便可
下山。
LONG
);
	set("exits", ([
		"west" : __DIR__"tanhai",
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

