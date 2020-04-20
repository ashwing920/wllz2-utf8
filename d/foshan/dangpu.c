//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: /d/foshan/dangpu.c

inherit ROOM;

void create()
{
	set("short","英雄典当");
	set("long",@LONG
当铺里一张高高的柜台，柜台后面坐着当铺的朝奉。这家当铺是凤老
爷所开，十多年来从没人来闹过事，朝奉也就很放心。柜台上挂着一个木
牌子(paizi)。
LONG
);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : @TEXT
公平交易

sell	卖 
buy	买
value	估价

TEXT
	]));
	set("objects", ([
		__DIR__"npc/chaofeng": 1,
	]));
	set("exits",([
		"north"  : __DIR__"street5",
	]));
	setup();
	replace_program(ROOM);
}

