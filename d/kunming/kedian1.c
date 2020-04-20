// Room: /city/kedian2.c

inherit ROOM;

void create()
{
	set("short", "客店二楼");
	set("long", @LONG
这里是客店的二楼几张大床一字排开，一些人正在上面睡的呼噜震天
响，门窗紧闭，官衔昏暗，你不由也想睡山个一觉。
LONG
);
	set("sleep_room",1);
	set("exits", ([
		"eastdown" : __DIR__"kedian",
	]));
	setup();

}
int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
	object me;

	me=this_player();
	if(!arg || arg!="大床") return 0;
	message_vision("$N用力把大床床移开，发现里面竟然有一条秘密通道！\n",me);
	me->move("/d/wudu/xiuxishi");
	tell_object(me,"走出密道发现，你出现在一个休息室内。\n");
	return 1; 
}