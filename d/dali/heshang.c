//Room: /d/dali/heshang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","河上");
	set("long",@LONG
你正身处波涛滚滚的泸水之上百多尺的空中。这是一座乌夷族特有之
藤桥，三根粗大的藤条呈一个倒“品”字形，脚踩下面一条，手扶左右两
条，攀援而过看来惊险，实际上倒也不十分困难。一阵山风挟着脚下激流
飞溅的水花吹过，你感到一阵寒意。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"east"	  : __DIR__"cangshanlu1",
		"west"	  : __DIR__"hebian",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	me = this_player();
	if (me->query_dex()<25)
	{
		tell_object(me,"你往藤桥下看了一眼，忽然怕了。\n");
		me->unconcious();
	}
	return 1;
}
