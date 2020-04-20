// xiaoqiao.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","小木桥");
	set("long",@LONG
这是不夜舫的老板为了方便客人出入而特意架设的小木桥，你站在铺
着红色地毯的小木桥上，不禁把不夜舫瞧个清楚。只见不夜舫有两层高，
不夜舫的两边都垂挂着纱帐，偷过纱帐，隐约可以看见不夜舫里的客人们
，正在把酒言欢。船头两边都挂着画满图案的灯笼，在威风吹拂下，显得
格外好看。
LONG
);
	set("outdoors","center");
	set("exits",([
		"west": __DIR__"buyefang/main-01",
		"east": __DIR__"roadw5",
	]));
}