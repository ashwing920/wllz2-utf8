// Room: /d/henshan/hsroad3.c 黄土路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。西面不远就
是衡阳县城了。
LONG
);
	set("outdoors", "henshan");
	set("exits", ([
		"northeast": __DIR__"hsroad2",
		"west"	 : __DIR__"hengyang",
	]));
	setup();
	replace_program(ROOM);
}

