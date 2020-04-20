// Room: /d/kunlun/ssy.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "三圣坳");
	set("long", @LONG
这里长年人迹罕至。谷中古树参天，绿荫森森，白雪皑皑，简直让人
疑心自己到了世外桃源。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"wft",
	]));
	set("objects",([
		__DIR__"npc/jinguanshe":3,
	]));
	set("outdoors","kunlun");
	setup();
	replace_program(ROOM);
}
