//main1.c
// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short","山洞之外");
	set("long",@LONG
你来到了华山脚下的一个无名的山洞，洞口不大，只能容纳一个人行
走。洞口铺着一层干草，脚下的泥土有些松动，想必是刚有人从这里进去
。从这里往洞里望去，却什么也看不到。
LONG);

	set("outdoors","daozeishandong");
	set("exits",([
		"north": __DIR__"level1/entry",
	]));
	set("item_desc",([
		"干草": "一垛干草掩盖着洞口，从脚下松动的泥土看去，想必这里经常有人走动。\n",
	]));
}
void init()
{
	add_action("do_bo","bo");
}
int do_bo(string arg)
{
	object me;
	me = this_player();

	if(!arg || arg =="") return 0;
	if( arg == "caocong" || arg == "草丛"){
		message_vision("$N拨开草丛，发现前方有一条小道。\n",me);
		set("exits/out","/d/huashan/path1");
		remove_call_out("close_path");
		call_out("close_path",8);
		return 1;
	}
}
void close_path()
{
	delete("exits/out");
}
int valid_leave(object me,string dir)
{
	if(dir == "north" && me->query_team())
		return notify_fail("洞口太小，只能一个人走进去。\n");
	if(dir == "out"  && !userp(me) && !me->query("savenpc"))
		return notify_fail("那里不是你能去的地方。\n");

	return ::valid_leave(me,dir);
}
