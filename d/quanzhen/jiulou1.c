// jiulou1.c
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "酒楼");
	set("long", @LONG
这家酒楼是武功镇方圆百里内的唯一一家，不过连名字都没有。楼下
布置简易，顾客多是匆匆的行人，买点包子、鸡腿、米酒就赶路去了。楼
上是雅座。
LONG
);
	set("exits", ([
		"south" : __DIR__"beijie",
		"up" : __DIR__"jiulou2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	setup();
	replace_program(ROOM);
}

