// main-01.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","不夜舫");
	set("long",@LONG
沿着小桥，你踏上不夜舫的船头，只见船头上铺设着一层红色的地毯
，显得十分尊贵。抬头仰望，不夜舫大门上挂着一块金字牌匾，上面龙飞
凤舞的写着「不夜舫」三个大字，两边还挂着粉红色的灯笼。站在这里，
不时可以听见不夜舫里传来阵阵嬉闹声。
LONG
);
	set("outdoors","center");
	set("exits",([
		"enter": __DIR__"main-02",
		"east": "/d/center/xiaoqiao",
	]));
}