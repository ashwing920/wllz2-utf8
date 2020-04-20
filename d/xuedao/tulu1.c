// mishi.c 密室
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条土路,不知通往哪,你回头还来得及。
LONG
);
	set("exits", ([
		"up" : __DIR__"xiaoshi",
		"out" : "/d/city/lichunyuan",
	]));
	setup();
	replace_program(ROOM);
}

