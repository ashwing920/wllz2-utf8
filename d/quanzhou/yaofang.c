//Cracked by Kafei

inherit ROOM;

void create()
{
	set("short", "药房");
	set("long", @LONG
这里是济世堂配药炼药的地方，屋子正中放了一只炼药炉，一个小厮
正不停的加药、鼓火、添水，炉中不停的冒出腾腾水雾，并散发着浓浓的
药气。
LONG
);
	set("exits", ([
		"west" : __DIR__"yaopu",
	]));
	set("objects", ([
		__DIR__"npc/xiaosi" : 1,
		__DIR__"yaopu/yaolu":1,
	]));
	setup();
	replace_program(ROOM);
}