// Room: /d/suzhou/dangpu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "宝和记");
	set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，
柜台上摆着一个牌子(sign)，柜台后坐着位老板，一双精明的眼睛上上下
下打量着你。
LONG
);
	set("exits", ([
		"north"  : __DIR__"dongdajie1",
	]));
	set("item_desc", ([
		"sign" : @TEXT
公平交易
sell	  卖 
buy	  买
value	  估价
pawn      典当
TEXT
	]));
	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

