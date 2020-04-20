// Room: /d/fuzhou/dongmen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "福州东门");
	set("long", @LONG
东门外是福州平原。从这里看去，可以见到密密的丛林。出东门十里
地就是鼓山了。
LONG
);
	set("exits", ([
		"east" : __DIR__"shulin",
		"west" : __DIR__"dongxiaojie",
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

