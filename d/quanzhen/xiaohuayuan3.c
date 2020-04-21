// xiaohuayuan3.c 小花园
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "小花园");
	set("long", @LONG
这里是重阳观里的小花园，种植着一些叫不出名字来的花木，园角砌
着一座假山，假山下是一潭小小的金鱼池，池水清澈见底，你看见有数条
红色的金鱼在里面悠哉游哉地游来游去。几个道童正在这里嬉戏着。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([
		"west" : __DIR__"xiaohuayuan2",
	]));

	set("objects", ([
		__DIR__"npc/daotong" : random(2),
	]));

	setup();
	replace_program(ROOM);
}