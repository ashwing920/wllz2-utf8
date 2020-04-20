// chufang.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","不夜舫厨房");
	set("long",@LONG
这里是供应不夜舫一切食物的厨房。一个足有半人高的灶头铸在厨房
的右边角落里，两个伙头正忙着为客人们做菜。厨房中间有一张大木桌，
上面放着一些已经做好的食物，等小伙计给客人们送去。东边有一扇门，
通往杂货房。
LONG
);
	set("exits",([
		"west":	__DIR__"zahuofang",
		"east": __DIR__"main-2f",
	]));
	setup();
}