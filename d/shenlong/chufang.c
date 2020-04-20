// Room: chufang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这是神龙岛的厨房，中央摆着大圆桌，周围则放着几张竹椅。神龙岛
的弟子都在这里用餐。
LONG
);
	set("exits",([
		"west" :__DIR__"zoulang",
	]));
	set("objects",([
		"/clone/food/jitui" : 3,
		"/clone/food/jiudai" : 1,
	]));
	setup();
	replace_program(ROOM);
}

