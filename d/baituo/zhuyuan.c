//zhuyuan.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","竹园");
	set("long",@LONG
这里是一个幽静的竹园，高高低低的翠竹把这里装点得别有情致。西
北方是后院，东北方有个兔苑。南边是花园。
LONG
);
	set("exits",([
		"northeast" : __DIR__"tuyuan",
		"northwest" : __DIR__"houyuan",
		"south" : __DIR__"huayuan",
	]));
	set("outdoors", "baituo");
	setup();
	replace_program(ROOM);
}

