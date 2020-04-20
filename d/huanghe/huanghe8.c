// Room: /huanghe/huanghe8.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "黄河入海口");
	set("long", @LONG
黄河流经青藏高原、黄土高原、华北平原，总长一万零九百里，在这
里汇入大海。
LONG
);
	set("exits", ([
		"southwest" : __DIR__"huanghe7",
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

