// gebi
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "戈壁");
	set("long",@LONG
这里是临近沙漠的戈壁滩，荒无人烟。东边是一望无际的大沙漠，西
北方可以看见一座小镇。
LONG
);
	set("outdoors","baituo");
	set("exits", ([
		"east" : "/d/xingxiu/shamo4",
		"northwest" : __DIR__"dongjie",
	]));
	setup();
	replace_program(ROOM);
}
