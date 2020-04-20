// beidajie1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "玄冰石室大门");
	set("long", @LONG
这里是位于泰山顶端的玄冰石室大门，刚踏入玄冰石室大门，顿觉阵
阵阴寒之气袭上心头。往石室内望进去，只见石室内十分宽敞，石室顶端
，挂着一道道冰柱，隐隐的水珠不断地往下滴淌，地面上三两步就可见到
一滩水迹，把原本干燥的地面弄得滑溜溜的。
LONG
	);
	set("objects", ([
		__DIR__"npc/shouwei": 1,
	]));
	set("exits", ([
		"north" : __DIR__"ready",
		"south" : "/d/taishan/fengchan",
	]));
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	set("no_beg",1);
	set("no_sleep_room",1);
	setup();
}
int valid_leave(object me, string dir) 
{ 
	if (dir == "north") 
		return notify_fail("石室守卫喝道：嘿！你给我站住！那儿不能随意进入。\n"); 
	return ::valid_leave(me, dir); 
} 
