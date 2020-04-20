// Room: /d/wudu/road1. c

inherit ROOM;

void create()
{
	set("short", "峭壁");
	set("long", @LONG
你攀登在一面陡峭的悬崖上，也不知道是谁在这上面凿出了一条是分
狭窄的道路，仅能供一两人走，向下看去，万丈深渊，另人咋舌抬头则不
见山顶在何处，可谓十分险峻。
LONG
);
	set("outdoors", "wudu");
	set("exits", ([
		"north" : __DIR__"milin/entry",
		"down" : __DIR__"qiaobi4",
	]));
	setup();
	replace_program(ROOM);

}

