//roadw5.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","桃源西码头");
	set("long",@LONG
沿着桃源西街，你来到了桃源城西面的码头，一片汪洋大海出现在你
的眼前。码头南边停泊着几艘小船，专门提供给出入于桃源城商人和游客
们的使用的，几个船夫正坐在码头边上，等待客人的召唤。码头西边长期
停泊着一艘画舫，那就是桃源城日夜歌舞升平的“$HIY$不夜舫$NOR$”了。不夜舫足
有十来丈长，六丈多宽，不夜舫的老板为了方便客人出入，还特意在码头
边上架设了一座拱形的小木桥呢。
LONG
);
	set("outdoors","center");
	set("exits",([
		"west": __DIR__"xiaoqiao",
		"east": __DIR__"roadw4",
	]));
}