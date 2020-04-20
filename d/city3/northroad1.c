// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: northroad1.c

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这里就是北大街了，空气中有着一种怪怪的气味，不是太好闻。路很
宽，但人却不多，尤其是在黄昏以后。西南是另一条大街，北大街从此一
直往东，西北有一家兵器铺，进进出出的人都面无表情，死气沉沉。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"east"	   : __DIR__"northroad2",
		"southwest"  : __DIR__"westroad3",
		"northwest"  : __DIR__"bingqidian",
	]));
	
	setup();
	replace_program(ROOM);
}
