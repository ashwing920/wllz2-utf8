// /d/xingxiu/mogaoku.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "莫高窟");
	set("long", @LONG
这里墙壁上绘制着与佛教相关的画面，有仙女飞天，还有反弹琵琶。
洞中还有很多佛像和经书。你被这些瑰丽的文化之宝惊呆了。
LONG
);
	set("exits", ([ 
		 "north" : __DIR__"yueerquan",
	]));
	setup();
	replace_program(ROOM);
}

