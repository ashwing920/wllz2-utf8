// square.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是华山剑派的练武场，场上立这几个木人，东边是兵器库，西边
是个小店。通常有许多华山剑派弟子在此习武练剑。北边的房屋门上挂着
一块匾，上书「群仙观」，西北方似乎有条小道通往山上。
LONG
);
	set("exits", ([
		"northwest" : __DIR__"chaopath1",
		"south"  : __DIR__"yunu",
		"north"  : __DIR__"qunxianguan",
		"west"    : __DIR__"shop",
		"east"    : __DIR__"bingqifang",
	]));
	set("objects", ([
		"/d/city3/npc/xiangpi-ren" : 5,
	]));
	set("outdoors", "huashan");

	setup();
}
 
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam=(mapping)me->query("family");
	if ((!myfam ||myfam["family_name"] != "华山剑派") && (dir == "east"))
		return notify_fail("那边是华山剑派的兵器库，这位" + RANK_D->query_respect(me) + "请止步。\n");
	return ::valid_leave(me, dir);
}
