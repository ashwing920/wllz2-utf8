//shanlu1.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","山路");
	set("long",@LONG
这里是山上的泥路。
LONG
);
	set("exits",([
		"north" : __DIR__"shulin",
		"southeast" : __DIR__"shanlu",
	]));
	set("outdoors", "baituo");
	set("objects" ,([
		__DIR__"npc/qiaofu" : 1 ,
	]) );
	setup();
	replace_program(ROOM);
}

