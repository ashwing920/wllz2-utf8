//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: wdroad.c 大道

inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
你走在一条黄土大道上，不时地有人挂剑跨马匆匆而过。东北通向武
当。
LONG
);
	set("outdoors", "emei");
	set("exits", ([
		"southwest" : __DIR__"xiaolu1",
		"northeast" : "/d/wudang/sanbuguan",
	]));

	setup();
	replace_program(ROOM);
}

