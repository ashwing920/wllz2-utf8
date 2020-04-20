// Room: /d/xingxiu/xxroad5.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "星宿派储藏室");
	set("long", @LONG
这里原来是一个长在山壁上的天然溶洞，因为地点隐密而且洞中空气
十分干燥，星宿派把这里改造成了一个仓库。
LONG
);
	set("exits", ([
		"out" : __DIR__"xxroad5",
	]));
	set("objects", ([
		__DIR__"obj/yanwu" : 1,
		__DIR__"obj/hulu" : 2,
		__DIR__"obj/menghan_yao" : 1,
		__DIR__"obj/xxqingxin-san" : 1,
		"/clone/book/dujing_1"  : 1
	]));
	set("outdoors", "xingxiuhai");

	setup();
	replace_program(ROOM);
}
