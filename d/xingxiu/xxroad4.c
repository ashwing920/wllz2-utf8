// Room: /d/xingxiu/xxroad4.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一条在山壁上人工开凿出来崎岖的小路上，这里，寒风凛冽，
西面是望不见底的深涧。
LONG
);
	set("exits", ([
		"southdown" : __DIR__"tianroad3",
		"north" : __DIR__"xxroad5",
	]));
	set("outdoors", "xingxiuhai");
	setup();
	replace_program(ROOM);
}
