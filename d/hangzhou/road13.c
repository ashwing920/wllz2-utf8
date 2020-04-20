// road13.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
沿湖大道旁店铺林立，长街故朴，屋舍鳞次栉比，道上人来车往，一
片太平热闹景象。街东边有一家客店。
LONG
);
	set("exits", ([
		"north"	 : __DIR__"road12",
		"southwest" : __DIR__"road14",
		"east"	  : __DIR__"kedian",
	]));
	set("objects", ([
		__DIR__"npc/zhang": 1,
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
