// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: southroad2.c

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
你正走在成都府的南大街上，这是一条宽敞开阔的大路，一直向两边
延伸。路上行人来来往往，好不热闹。一些小商小贩常在这里做些小买卖
南面是南门，北边一条大道名叫提督街，你一看就知到为啥那麽安静了。
LONG
);
	set("outdoors", "chengdu");
	set("exits", ([
		"north"  : __DIR__"tiduroad",
		"south"  : __DIR__"southgate",
		"east"   : __DIR__"southroad1",
		"west"   : __DIR__"southroad3",
	]));
	
	setup();
	replace_program(ROOM);
}
