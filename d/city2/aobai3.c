//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "鳌府大院");
	set("long", @LONG
你走进大院，迎面是一个假山水池，池中立着一块巨大无比的翡翠，
显然是鳌拜收刮来的宝物。水池的两旁种满了花草。北边是厨房，有一棵
槐树，郁郁葱葱，遮盖了大半个院子，显得阴森恐怖。西边一条长廊走道
通往后院，有几个官兵把守。
LONG
);
	set("exits", ([
		"west" : __DIR__"aobai4",
		"east" : __DIR__"aobai2",
		"north" : __DIR__"aobai5",
	]));
	set("objects", ([
		__DIR__"npc/wuzhirong" : 1,
	]));

	setup();

	replace_program(ROOM);
}

