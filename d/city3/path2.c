// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: path2.c

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "溪岸小路");
	set("long", @LONG
溪源转北，阵阵水响带着你来到草堂前。站在草堂照壁前，回首浣花
溪，想象万红漂坠，少女清歌浣花时节，别是一般滋味。北边就是“万里
桥西宅，百花潭北庄”的杜甫草堂了。
LONG
);
	set("outdoors", "chengdu");
	set("exits", ([
		"north"  : __DIR__"caotang",
		"south"  : __DIR__"path1",
	]));
	
	setup();
	replace_program(ROOM);
}
