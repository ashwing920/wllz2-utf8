// chanfang2.c 禅房
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "禅房");
	set("long", @LONG
这里是全真弟子修身养性、打熬气力的地方。为了方便练功，桌椅都
没有摆放，仅仅在地下丢了几个小蒲团。
LONG
	);
	set("exits", ([
		"east" : __DIR__"chanfang3",
		"west" : __DIR__"chanfang1",
		"south" : __DIR__"liangong",
	]));
	setup();
	replace_program(ROOM);
}
