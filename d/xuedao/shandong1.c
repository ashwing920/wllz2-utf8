// shandong1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","山洞");
	set("long",@LONG
空空荡荡一个山洞，倒也还算干净，尽头摆了一张石床。
LONG
);
	set("exits",([
		"out" : __DIR__"sroad8",
	]));
	set("objects", ([
		__DIR__"obj/dachang" :1,
	]));
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
	replace_program(ROOM);
}

