// chongyanggate.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "重阳宫大门");
	set("long", @LONG
你已走到了终南山半山腰，前面就是全真教的总部重阳宫了。殿宇依
山而筑，高低错落有致。周围古木森森，翠竹成林，景色清幽。正前方黄
墙碧瓦，飞檐翘檩，正中一道二丈来宽，三丈来高的朱红杉木包铜的大门
(door)。上方一块大匾，龙飞凤舞地书着『重阳宫』三个大字。南下是广
场。
LONG
);
	set("outdoors", "gumu");
	set("exits", ([
		"southdown"   : __DIR__"daxiaochang",
	]));

	setup();
	replace_program(ROOM);
}
