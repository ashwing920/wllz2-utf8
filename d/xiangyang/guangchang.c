// Room: /d/xiangyang/guangchang.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "中央广场");
	set("long", @LONG
这里是襄阳的中央广场，铺着青石地面。东面通向青龙门，西面通向
白虎门，南面直达朱雀门，远远地你可看到北面是襄阳安抚使衙门。近年
来蒙古大军屡次攻打襄阳，官府为防止蒙古奸细混杂进来，已经不允许人
们在此聚集。只见一队官兵在此往来巡逻，你还是快离开吧。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"east"  : __DIR__"eastjie1",
		"west"  : __DIR__"westjie1",
		"south" : __DIR__"southjie1",
		"north" : __DIR__"anfupailou",
	]));
	set("objects", ([
		__DIR__"npc/pian" : 1,
		__DIR__"npc/bing" : 1,
	]));
	setup();
	replace_program(ROOM);
}

