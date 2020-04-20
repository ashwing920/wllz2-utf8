// gytoad1.c 果园小路
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "果园小路");
	set("long", @LONG
眼前豁然开朗，你轻松地走在果园边的小路上。路上落英缤纷，两边
是桃树林，盛开着粉红的桃花，红云一片，望不到边。还可以看蜜蜂「嗡
嗡」地在花间飞上飞下忙个不停，间或传来猿猴的叽咋声。
LONG
);
	set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"tyroad13",
		"east" : __DIR__"gyroad2",
	]));
	set("objects", ([
		__DIR__"npc/snake": 1
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();
	if ( dir == "east" && objectp(present("ju man", environment(me))))
		return notify_fail(RED"朱冠巨蟒"NOR"一跃拦住你的去路。\n");

	return ::valid_leave(me, dir);
}
