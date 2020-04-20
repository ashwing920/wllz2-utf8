// baichi.c

inherit ROOM;

void create()
{
	set("short", "观瀑亭");
	set("long", @LONG
玉屏瀑侧的这座观瀑亭，真是绝好的览秀圣地，站在此处，飞溅的玉
屏瀑，如镜的百丈泉，无不尽收眼底。
LONG
);
	set("exits", ([
		"south" : __DIR__"yupingpu",
		"northup" : __DIR__"moyun",
	]));
	set("objects", ([
		__DIR__"npc/youke": 1,
	]));
	set("outdoors","riyue");
	setup();
	replace_program(ROOM);
}
 
