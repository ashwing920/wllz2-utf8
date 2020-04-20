// Room: /huanghe/gulang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "古浪");
	set("long", @LONG
古浪城建于西周，本名鬼武，后整修于汉，更名古浪。古浪是西北地
区的毛皮集散地，当初的紫羊羔皮袄，一出于张家口，另一出处就是古浪
了，过了古浪再往西四十里，跨过纪水河即到兰州。
LONG
);
	set("exits", ([
		"south"	 : __DIR__"yongdeng",
		"north"	 : __DIR__"xueguan",
		"east"	  : __DIR__"yaocaidian",
		"west"	  : __DIR__"xiaojiaqiao",
		"northeast" : __DIR__"dacaigou",
	]));
	set("objects", ([
		"/d/taishan/npc/dao-ke" : 1,
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

