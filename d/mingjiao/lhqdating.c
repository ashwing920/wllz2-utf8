//lhqdating.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "烈火旗大厅");
	set("long", @LONG
这里是烈火旗的大厅，厅中红旗招展，刀枪映血，教众绛衣赤帽，团
团拥住烈火旗掌旗使辛然。
LONG
);
	set("exits", ([
		"west" : __DIR__"lhqyuan",
	]));
	set("objects", ([
		__DIR__"npc/xinran": 1,
	]));
	setup();
	replace_program(ROOM);
}
