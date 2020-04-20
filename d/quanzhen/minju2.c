// minju2.c 民居
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这是一家用茅草搭的房屋，家徒四壁，屋角的米缸是空的，厨房内的
水缸也是空的。几个缺胳膊少腿的桌椅靠墙立着。看来主人已经把所有能
值钱的东西全都变卖了。
LONG
	);
	set("exits", ([
		"south" : __DIR__"xijie",
	]));
	setup();
	replace_program(ROOM);
}
