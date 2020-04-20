// Room: /d/xiangyang/guofugate.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "郭府大门");
	set("long", @LONG
一座建筑古朴的大宅院出现在你的眼前。只见门楼高挑，上书两个大
字郭府。全真教第二代弟子耶律齐和几个家丁站在门前接待前来保卫襄阳
的各方义士。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"south" : __DIR__"westjie1",
		"north" : __DIR__"guofuyuan",
	]));
	set("objects", ([
		__DIR__"npc/yelvqi" : 1,
		__DIR__"npc/jiading" : 2,
	]));
	setup();
	replace_program(ROOM);
}

