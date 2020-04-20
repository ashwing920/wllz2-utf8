// sjqiao.c 顺济桥

inherit ROOM;

void create()
{
	set("short", "顺济桥");
	set("long", @LONG
这是横跨晋河的一座石拱桥。桥宽水深，水陆交通便捷，是南去的唯
一出口。一队官兵驻扎在这里。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"hjting",
		"south" : __DIR__"gangkou1",
		"southeast" : __DIR__"shijiefu",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
