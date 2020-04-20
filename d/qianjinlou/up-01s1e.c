// up-01s1e.c - 千金楼（厢房）

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
这里是千金楼二楼一间普通的厢房。厢房里收拾得十分干净，一张大
床陈列在厢房的右侧，床上挂着一廉粉红色的床帘，十分好看。厢房中央
有一张八仙桌，几个女子正坐在桌旁，窃窃私语，好象在谈论些什么。
LONG
);
	set("exits", ([
		"west"  : __DIR__"up-01s1",
	]));
	set("objects",([
		__DIR__"npc/mingji-l": 1,
		__DIR__"npc/jinu": 2,
		__DIR__"npc/yahuan": 1,
	]));

	setup();

	replace_program(ROOM);
}