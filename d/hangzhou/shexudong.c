// shenxudong.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "射旭洞");
	set("long", @LONG
洞後侧穹顶上的石罅间可仰见一束天光，故又名“一线天”。东南边
是下山的路。
LONG
);
	set("exits", ([
		"southeast" : __DIR__"longhongdong",
	]));
	set("objects", ([
		 __DIR__"npc/mengmian":1,
	]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
