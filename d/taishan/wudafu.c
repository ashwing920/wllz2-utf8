// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "五大夫松");
	set("long", @LONG
相传当年秦始皇上泰山，来到这里下起雨来，他就到两棵松树底下避
雨，结果没淋着。因此，他就封这两棵松树为「五大夫」。后来不知从哪
里来了一块巨大的飞来石把两棵松树砸死了。后人再在旁补种五株松树。
在不远处还有一个御帐坪，据说就是秦始皇当年结帐的位置。从这里再往
山上走便会到达十八盘的入口。
LONG
);
	set("exits", ([
		"northup" : __DIR__"longmen",
		"southdown" : __DIR__"ertian",
	]));
	set("outdoors", "taishan");
	setup();
}
int valid_leave(object me,string dir)
{
	if(dir == "northup")
	if(random((int)me->query_skill("dodge")) <= 50){
		me->receive_damage("qi", 50);
		message_vision(HIR"$N一不小心脚下踏了个空，... 啊...！\n"NOR, me);
		me->move(__DIR__"daizong");
		tell_object(me, HIR"你从山上滚了下来，只觉得浑身无处不疼，还受了几处伤。\n"NOR);
		message("vision", HIR"只见" + me->query("name") + "从山上骨碌碌地滚了下来，躺在地上半天爬不起来！\n"NOR, environment(me), me);
	}
	return ::valid_leave(me, dir);
}

