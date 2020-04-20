// Room: /d/xiangyang/southgate2.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "朱雀外门");
	set("long", @LONG
这里是襄阳城的南城门，只见城门上方是三个大字。朱雀门近年来蒙
古屡次侵犯襄阳城，故这儿把守相当严密，一些官兵们正在盘查要离襄阳
城的人。两边是很大的草地。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"east"   : __DIR__"caodi4",
		"west"   : __DIR__"caodi5",
		"south"  : __DIR__"caodi6",
		"north"  : __DIR__"southgate1",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}

