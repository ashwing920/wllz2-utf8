//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "竹林小道");
	set("long", @LONG
四周都是密密的竹林，一踏进这里你就迷了路。这里人迹罕至，惟闻
足踏草坪之声。偶尔有微风轻拂竹叶，又如簌簌禅唱，令人尘心为之一涤
，真是绝佳的清修所在。
LONG
);
	set("exits", ([
		"northeast" : __FILE__,
		"southwest" : __FILE__,
		"east" : __FILE__,
		"west" : __FILE__,
		"south" : __DIR__"zhulin4",
		"north" : __DIR__"xiaoyuan",
	]));

	create_door("north","竹门","south",DOOR_CLOSED);
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}

