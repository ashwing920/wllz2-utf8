// Room: /d/henshan/hsroad8.c 林间道
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "林间道");
	set("long", @LONG
这里是一条林间小道，在树丛中蜿蜒。西北方连着一条黄土路，南面
的道路要宽一些。
LONG
);
	set("outdoors", "henshan");

	set("exits", ([
		"northwest" :"/d/wudang/wdroad9",
		"south"	 : __DIR__"hsroad7",
	]));
	setup();
	replace_program(ROOM);
}

