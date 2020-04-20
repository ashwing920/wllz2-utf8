// Room: /d/xiangyang/northgate2.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "玄武外门");
	set("long", @LONG
这里是襄阳城的北城门，只见城门上方是三个大字。玄武门近年来蒙
古屡次侵犯襄阳城，故这儿把守相当严密，一些官兵们正在盘查要离襄阳
城的人。两边是很大的草地。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"south"  : __DIR__"northgate1",
		"north"  : __DIR__"caodi3",
		"east"   : __DIR__"caodi1",
		"west"   : __DIR__"caodi2",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}

