// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: shuduroad1.c

inherit ROOM;

void create()
{
	set("short", "蜀都大道");
	set("long", @LONG
这里是蜀都大道，向西就可以到提督府了。过往的车马卷起阵阵尘土
，来去的官差阵步如飞，有一些官兵在路上巡哨。你感到一点点害怕，真
后悔拐进这里来。
LONG
);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"eastroad2",
		"west"  : __DIR__"guangchang",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	
	setup();
	replace_program(ROOM);
}
