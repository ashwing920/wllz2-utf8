// Room: /d/quanzhou/jxnanmen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "嘉兴南门");
	set("long", @LONG
这里是嘉兴的南门。周围长着茂密的竹林。东面是座庙宇。向南可入
福建。向东南就是号称天堂的杭州城了。
LONG
);
	set("exits", ([
		"north" : __DIR__"jiaxing",
		"east" : __DIR__"tieqiang",
		"south" : __DIR__"qzroad4",
		"southeast": "/d/hangzhou/road1",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

