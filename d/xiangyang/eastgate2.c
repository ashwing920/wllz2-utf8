// Room: /d/xiangyang/eastgate2.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

#include <ansi.h>;

void create()
{
	set("short", "青龙外门");
	set("long", @LONG
这里是襄阳城的东城门，只见城门上方是三个大字。青龙门近年来蒙
古屡次侵犯襄阳城，故这儿把守相当严密，一些官兵们正在盘查要离襄阳
城的人。两边是很大的草地。
LONG
 );
	set("outdoors", "xiangyang");
	set("exits", ([
		"west"  : __DIR__"eastgate1",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
	replace_program(ROOM);
}

