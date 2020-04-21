// Room: /d/shaolin/zhulin2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "竹林小道");
	set("long", @LONG
这是一条卵石铺成的小道，曲曲折折地通向前方。两边是密密的竹林
。这里人迹罕至，惟闻足底叩击路面，有僧敲木鱼声；微风吹拂竹叶，又
如簌簌禅唱。令人尘心为之一涤，真是绝佳的禅修所在。
LONG
);
	set("exits", ([
		"east" : __DIR__"wuqiku",
		"west" : __DIR__"hsyuan2",
		"south" : __DIR__"zhulin1",
		"north" : __DIR__"zhulin3",
	]));
	set("outdoors", "shaolin");
	create_door("east","木门","west",DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
