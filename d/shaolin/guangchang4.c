// Room: /d/shaolin/guangchang4.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "精进场");
	set("long", @LONG
这是后殿前的精进场，广场青砖铺地，因为多年的踩踏而凹凸不平。
前后各是两堵高墙，把整个广场拘在中间，形成一个窄窄的长方形。西边
开了扇小门，一股香气袅袅地飘了过来。北面是个大门，几位僧人在此把
守。
LONG
);
	set("exits", ([
		"south" : __DIR__"guangchang3",
		"northup" : __DIR__"houdian",
	]));
	set("outdoors", "shaolin");
	set("objects",([
		CLASS_D("shaolin") + "/hui-kong" : 1,
		__DIR__"npc/seng-bing3" : 2,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "少林派") && dir == "northup" &&
		objectp(present("hui kong", environment(me))))
			return notify_fail("慧空喝道：你不是少林出家弟子，不得进入后殿。\n");
	return ::valid_leave(me, dir);
}

