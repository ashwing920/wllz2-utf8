//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
// gudi.c

inherit ROOM;

void create()
{
	set("short", "谷底");
	set("long", @LONG
但听得耳边轰聋聋的响声越来越大，山崖也逐渐变得倾斜，而不再象
上面那么陡峭笔立了，终于到达谷底了。只见上面的上崖一条大瀑布如玉
龙悬空，滚滚而下，倾入了一座清澈异常的大湖之中，甚为壮观。
LONG );
	set("exits", ([
		"up" : __DIR__"yanfeng",
		"west" : __DIR__"hubian",
	]));
	set("outdoors", "xiaoyao" );

	setup();
	replace_program(ROOM);
}
