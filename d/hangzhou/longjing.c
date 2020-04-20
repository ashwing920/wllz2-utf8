// longjing.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "龙井");
	set("long", @LONG
只见井(jing)水澈可见底而且清冷异常。龙井原名龙泓涧，传说此井
与海相通，其中必定有龙，祈祷必雨，故名“龙井”。苏东坡曾有诗“人
言山佳水亦佳，下有万古蛟龙潭”。井旁建有茶室。往南便回大路。
LONG
);
	set("exits", ([
		"east"	 : __DIR__"chashi",
		"south"	: __DIR__"shanlu5",
	]));
	set("item_desc", ([
		"jing" : "井水清澈见底，井底部有一些豆状小颗粒叠起的小堆。\n",
	]));
	set("resource/water", 1);
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
