// Room: /d/shaolin/bamboo6.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
这是一片密密的竹林。这里人迹罕至，惟闻足底叩击路面，有僧敲木
鱼声；微风吹拂竹叶，又如簌簌禅唱。令人尘心为之一涤，真是绝佳的禅
修所在。
LONG
);
	set("exits", ([
		"west" : __DIR__"bamboo"+(random(13)+1),
		"east" : __DIR__"bamboo7",
		"south" : __DIR__"bamboo"+(random(13)+1),
		"north" : __DIR__"bamboo"+(random(13)+1),
	]));
	set("outdoors", "shaolin");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "east" ) 
	me->add_temp("bamboo/count", 1);
	else
	me->add_temp("bamboo/count", -1);
	return ::valid_leave(me, dir);
}

