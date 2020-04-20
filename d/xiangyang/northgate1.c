// Room: /d/xiangyang/northgate1.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "玄武内门");
	set("long", @LONG
这里是襄阳城的北城门的内城门，只见城门上方是三个大字。玄武门
近年来蒙古屡次侵犯襄阳城，故这儿把守相当严密，一些官兵们正在盘查
要离襄阳城的人。两边是上城头的石阶，向南进入城区。
LONG
);
	set("outdoors", "xiangyang");

	set("exits", ([
		"eastup" : __DIR__"walln1",
		"westup" : __DIR__"walln2",
		"south"  : __DIR__"northjie",
		"north"  : __DIR__"northgate2",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}

