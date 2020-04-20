// guangchang.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "广场");
	set("long",@LONG
这里是一块不小的广场，上面堆着农家晒的谷物。北上是白驼山庄。
东面有间小农舍，西边有块菜地，东南方是一座小桥。
LONG
);
	set("outdoors", "baituo");
	set("exits", ([
		"east" : __DIR__"nongshe",
		"northup" : __DIR__"shijie",
		"northwest" : __DIR__"shanlu",
		"southeast" : __DIR__"bridge",
	]));
	set("objects",([
		__DIR__"npc/kid" : 2,
	]));
	setup();
	replace_program(ROOM);
}
