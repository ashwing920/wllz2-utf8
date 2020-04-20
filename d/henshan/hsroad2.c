// Room: /d/henshan/hsroad2.c 黄土路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。
LONG
);
	set("outdoors", "henshan");
	set("exits", ([
		"northwest" : __DIR__"hsroad1",
		"southwest" : __DIR__"hsroad3",
		"southeast" : "/d/fuzhou/fzroad7",
	]));
	setup();
	replace_program(ROOM);
}

