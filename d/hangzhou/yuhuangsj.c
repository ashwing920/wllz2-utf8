// yuhuangsj.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "玉皇山脚");
	set("long", @LONG
只见往上的山路曲折蜿延。山路旁有一座小六角亭，几个游人正在亭
里歇脚。东北边是一条青石大道，往西是上山的路。
LONG
);
	set("exits", ([
		"northeast" : __DIR__"road15",
		"westup"	: __DIR__"shanlu7",
	]));
	set("objects", ([
		__DIR__"npc/honghua1" : 2,
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
