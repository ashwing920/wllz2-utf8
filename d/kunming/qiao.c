// /d/kunming/qiao

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","独木桥");
	set("long", @LONG
一座独木桥，也不知是什么时候架起来的，走在上面摇摇晃晃，很是
危险，当时要过河的话，只有走这里。从桥上望下去，只见急流勇潺，一
掉下去，肯定没命。
LONG
);
	set("outdoors", "kunming");
	set("exits", ([
		"south" : __DIR__"road6", 
		"north"  :__DIR__"road5",
	]));
	setup();
}
