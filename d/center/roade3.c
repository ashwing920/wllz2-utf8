// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "桃源东街");
	set("long", @LONG
你走在东大街上，踩着坚实的青石板地面。北边是一个集市。集市里
人头攒攒，不少商贩和游人正在集市中游览。叫卖声，讨价还价声震耳欲
聋，好不热闹。南面是一家车马店，据说车马店的老板擅长于驯养马匹艺
，在他手底下驯养出来的马匹，深得官府和江湖上一些侠客们的喜欢。许
多侠客都千里迢迢的慕名而来，在这里购买马匹做为自己的坐骑。
LONG
);
	set("outdoors", "center");
	set("exits", ([
		"east"  : __DIR__"roade4",
		"south" : __DIR__"madian",
		"west"  : __DIR__"roade2",
		"north" : __DIR__"jishi",
	]));
	set("objects", ([
		__DIR__"npc/drunk": 1 
	]));
	setup();
	replace_program(ROOM);
}
