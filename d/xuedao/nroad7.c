// nroad7.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","山路");
	set("long",@LONG
你走在一山路上，四周有一座座小山丘。
LONG
);
	set("exits",([
		"eastdown" : "/d/xueshan/shanjiao",
		"south"	: __DIR__"nroad6",
	]));
	set("objects",([
		CLASS_D("xuedao")+"/shanyong" : 1,
	]));
	set("outdoors", "xueshan");
	setup();
	replace_program(ROOM);
}

