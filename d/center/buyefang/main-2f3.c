// main-2f3.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","不夜舫二楼");
	set("long",@LONG
这里是不夜舫二楼的船头，船头边上挂着两串灯笼，上面写着：近水
楼台先得月，夜夜笙歌不夜舫。站在这里，环顾四方，一片汪洋大海呈现
在你的眼前，吹着海风听着海浪拍打的声音，让人倍感陶醉。一对青年男
女正站在桥头窃窃私欲，如此良辰美景，真是羡煞旁人。
LONG
);
	set("exits",([
		"north": __DIR__"main-2f2",
	]));
	set("objects",([
		"/d/center/npc/youngman": 1,
		"/d/center/npc/younglady": 1,
	]));
	setup();
}