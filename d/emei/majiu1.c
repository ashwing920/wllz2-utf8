//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: majiu1.c 马厩

inherit ROOM;

void create()
{
	set("short","马厩");
	set("long",@LONG
这是草棚边的马厩，常年供应新鲜草料。据说此地民风淳朴，马夫们
会把马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净，一直伺
候到客人上路。马厩中堆放著几堆草料，正中有一口泔槽。马厩雨檐下的
烂木柱上钉着一块破木牌(paizi)。
LONG
);
	set("outdoors", "emei");
	set("no_fight", "1");
	set("no_beg", "1");
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		"/d/city/npc/camel": 1,
		__DIR__"npc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往	  扬州城:   rideyz
	  峨嵋山腰: rideem

TEXT]));
	
	set("exits",([ 
		"east"	: __DIR__"caopeng",
	]));

	setup();
	replace_program(ROOM);
}
