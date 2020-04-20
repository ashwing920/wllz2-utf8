// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "天街");
	set("long", @LONG
此地在南天门东北，这里有数十户小贩聚而成市。从这里往东南走便
是莲花峰，东北是围屏山，西南便回到南天门。
LONG
);
	set("exits", ([
		"westdown" : __DIR__"nantian",
		"eastup" : __DIR__"weipin",
		"eastdown" : __DIR__"lianhua",
	]));
	set("objects",([
		__DIR__"npc/xiao-fan" : 1,
		__DIR__"npc/tiao-fu" : 2,
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

