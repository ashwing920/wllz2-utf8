// Room: /d/xiangyang/eastroad1.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "东内大街");
	set("long", @LONG
这是一条青石铺就的大街。西面是一堵盖着红色琉璃瓦的高墙，里面
是襄阳守城大将王坚的府邸大院。东面是是一座镖局，北面是用青石铺的
大街道。南面是一个大的十字街道，只见人来人往，非常热闹。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"east"  : __DIR__"biaoju",
		"south" : __DIR__"eastjie2",
		"north" : __DIR__"eastroad2",
	]));
	setup();
	replace_program(ROOM);
}
