// Room: /d/wudu/hsonglin3

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "毒龙洞口" );
	set("long", @LONG
你来到一个黑乎乎的洞口前，四周荒突突的，连杂草都没有，几个五
毒教的弟子把守着洞口，四周的空气中仿佛有一种神秘的力量，吸引着你
想进洞去看看。
LONG
);
	set("outdoors", "wudu");
	set("exits", ([
		"east" : __DIR__"hsonglin5",
		"enter" : __DIR__"dulongdong2",
	]));
	set("objects",([
		__DIR__"npc/dizi" : 4,
	]));
	setup();

}
int valid_leave(object me, string dir)
{               
	if (  !present("wudu ling", me) && ( dir == "enter" ) &&
		objectp(present("hudong dizi", environment(me))) )
			return notify_fail("护洞弟子拦住了你。\n");
		return ::valid_leave(me, dir);
}