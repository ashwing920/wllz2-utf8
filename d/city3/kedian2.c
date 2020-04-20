// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: /chengdu/kedian.c

inherit ROOM;

void create()
{
	set("short", "锦城驿二楼");
	set("long", @LONG
这是一间很大的客房，陈设十分简陋。靠墙放了十几张小木床，不少
客人正和衣而卧，满屋子都是呼呼的打酣声。你看到西边有张床是空的，
就蹑手蹑脚地走了过去。
LONG
);
	set("sleep_room",1);
	set("hotel",1);
	
	set("exits", ([
		"down" : __DIR__"kedian",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}
