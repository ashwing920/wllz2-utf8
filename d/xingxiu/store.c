// room: /d/xingxiu/nanjiang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这是一个杂货铺。房屋内铺着地毯。店老板坐在地毯上，旁边堆着他
的货。墙上有个牌子，是个价目表(sign)。
LONG
);
	set("exits", ([ 
		"east" : __DIR__"beijiang",
	]));
	set("objects", ([
		__DIR__"npc/maimaiti": 1
	]) );
	set("item_desc", ([ /* sizeof() == 1 */
		"sign" : @TEXT
牌子上写道：中原钱币通用。
	
	马奶酒壶(hu)	   一百文
	馕(nang)	   五十文
	火折(fire)	   一百文
	哈密瓜(gua)   	   四十文
	冬不拉(dongbula)   一百文
	伊犁马(horse)	  一千文 ( 售完 )
TEXT
	]));
	setup();
	replace_program(ROOM);
}

 
