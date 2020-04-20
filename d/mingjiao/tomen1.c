// Room: /d/mingjiao/tomen1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石阶");
	set("long", @LONG
石级到这里似乎变得宽阔了些。清新的山风扑面而来，令人精神顿为
一爽。远处传来淙淙水声，渐行渐远。山壁上挂满了厚密的藤萝，随风轻
轻摇弋。
LONG
);
	set("exits", ([
		"west" : __DIR__"shanmen",
		"east" : __DIR__"tomen2",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}

