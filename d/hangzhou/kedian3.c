// kedian3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "天外天客店二楼");
	set("long", @LONG
天外天客店果然名不虚传，好大的一间客房，一张精致的床，窗外是
美丽的西湖，无边的宜人景致。暖暖的风吹得你昏昏欲睡，这里正是睡觉
的好地方。
LONG
);
	set("sleep_room",1);
	set("hotel",1);
	set("exits", ([
		"out" : __DIR__"kedian2",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");
	return ::valid_leave(me, dir);
}

