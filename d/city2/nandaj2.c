//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "南大街广场");
	set("long", @LONG
这里是一个热闹的广场，正是北京城里最热闹、最杂乱的地段。一座
天桥横跨东西，正是卖杂货、变把戏、跑江湖的闲杂人等聚居的所在。宽
阔的大道向南北两头延伸。南边是永定门，通往郊外。北边是南大街，通
往天安门。东边是有名的“高升茶馆”，人们都爱在那儿休息聊天。西边
有一家很大的屠宰场，不时传来猪凄厉的哀嚎。
LONG
);
	set("outdoors", "city2");
	set("exits", ([
		"west" : __DIR__"tuzai",
		"south" : __DIR__"yongding",
		"east" : __DIR__"chaguan",
		"north" : __DIR__"nandaj1",
	]));
	set("objects", ([
		"/d/baituo/npc/snaker" : 1,
		"/d/taishan/npc/dao-ke" : 1,
		"/d/taishan/npc/jian-ke" : 1,
	]));

	setup();
	replace_program(ROOM);
}
