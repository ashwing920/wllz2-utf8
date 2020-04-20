// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "草地");
	set("long", @LONG
这里是一遍绿茵茵的草地，像是一方绿色的毯子铺在地上。草丛中开
着一些不知名的小花，有红的、黄的，还有紫的。花瓣上、草叶上的露珠
闪着晶莹的光。
LONG
);
	set("exits", ([
		"east" : __DIR__"caodi1",
		"west" : __DIR__"shulin1",
	]));
	set("objects", ([
		"/d/hangzhou/obj/eluanshi" : 1,
	]));
	set("outdoors", "huanghe");
	setup();

}

