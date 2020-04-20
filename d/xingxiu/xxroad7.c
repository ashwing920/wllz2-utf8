// Room: /d/xingxiu/xxroad7.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一条崎岖的小路上，这里荒无人烟，寒风凛冽。
LONG
);
	set("exits", ([
		"southeast" : __DIR__"xxroad6",
		"west" : __DIR__"xxroad8"
	]));
	set("outdoors", "xingxiuhai");
	setup();
	replace_program(ROOM);
}
