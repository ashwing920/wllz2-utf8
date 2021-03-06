//Room: majiu.c 马厩
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","马厩");
	set("long",@LONG
这是客栈边上的马厩，常年供应新鲜草料。据说此地民风淳朴，客人
只要住店，马夫们就会把马牵到马厩好生照看，将它们喂饱饮足，再洗刷
得干乾净净。一直伺候到客人离店上路。马厩中堆放著几堆草料，正中有
一口泔槽。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。
LONG
);
	set("outdoors","huanghe");
	set("no_fight",1);
	set("no_beg",1);
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		__DIR__"npc/mafu": 1,
	]));
	set("item_desc", ([
	"paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往	  扬州城:  rideyz
	  灵州城:  ridelz

TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"east"	  : __DIR__"kedian",
	]));
	setup();
	replace_program(ROOM);
}
