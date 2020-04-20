// houshan.c 后山
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "后山");
	set("long", @LONG
这里已经出了重阳宫，到了终南山的后山。这里鸟语花香，空气清新
，山势也平缓得多了。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([
		"west" : __DIR__"jingxiushi",
		"northeast" : __DIR__"xiaolu1",
	]));
	setup();
	replace_program(ROOM);
}

