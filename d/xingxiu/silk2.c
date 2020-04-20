//d/xingxiu/silk2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "丝绸之路");
	set("long", @LONG
这是一条中原和西域之间的商道。南面连绵的祁连山脉在阳光的照射
下好像是一条玉带。东边是中原，西面则通往西域。
LONG
);
	set("outdoors", "xingxiuhai");
	set("exits", ([
		"east" : __DIR__"silk1",
		"west" : "/d/mingjiao/westroad1",
		"northwest" : __DIR__"silk3",
	]));
	setup();
	replace_program(ROOM);
}

