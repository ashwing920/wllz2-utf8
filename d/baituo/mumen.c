//room: mumen.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","墓门");
	set("long",@LONG
这是个一座豪华墓地的墓门。大理石雕花的门梁，青石板的路面，修
剪整齐的长青木，显得庄重肃穆。墓门边立着一块青白色石碑。
LONG
);
	set("exits",([
		"south" : __DIR__"fende",
	]));
	set("objects",([
		__DIR__"npc/shiwei": 2,
	]));
	set("outdoors", "baituo");
	setup();
	
}