//shijie.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","石阶");
	set("long",@LONG
你走在青石板铺成的石阶上。这里就是传说中神秘的白驼山。远远望
去，两座白沙堆积形成的山峰好像一只骆驼的脊背。一座山门立在你的眼
前。
LONG
);
	set("exits",([
		"east" : __DIR__"caoping",
		"northup" : __DIR__"damen",
		"southdown" : __DIR__"guangchang" ,
	]));
	set("outdoors", "baituo");
	setup();
	replace_program(ROOM);
}

