//dongjie
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "东街");
	set("long",@LONG
这里是小镇的东街。南边有个打铁铺，里面传来丁丁当当的声音。东
南方是荒凉的戈壁，东北方有条小路可上山。
LONG
);
	set("outdoors", "baituo");
	set("exits", ([
		"west" : __DIR__"xijie",
		"south" : __DIR__"datiepu",
		"southeast" : __DIR__"gebi",
		"northeast" : __DIR__"xiaolu1",
	]));
	set("objects",([
		__DIR__"npc/playboy" : 1,
	]));
	setup();
	replace_program(ROOM);
}
