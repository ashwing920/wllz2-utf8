// road12.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
沿湖大道旁店铺林立，长街故朴，屋舍鳞次栉比，道上人来车往，一
片太平热闹景象。街东边是一古朴书院，书院里不时传来朗朗的笑声。
LONG
);
	set("exits", ([
		"north"	 : __DIR__"road11",
		"south"	 : __DIR__"road13",
		"east"	  : __DIR__"shuyuan",
	]));
	set("objects", ([
		__DIR__"npc/likexiu" : 1,
		__DIR__"npc/qingbing" : 4,
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}