// Room: /d/xiangyang/westgate1.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "白虎内门");
	set("long", @LONG
这里是襄阳城的西城门的内城门，只见城门上方是三个大字。白虎门
近年来蒙古屡次侵犯襄阳城，故这儿把守相当严密，一些官兵们正在盘查
要离襄阳城的人。两边是上城头的石阶，向东进入城区。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"southup" : __DIR__"wallw2",
		"northup" : __DIR__"wallw1",
		"east"	: __DIR__"westjie3",
		"west"	: __DIR__"westgate2",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}

