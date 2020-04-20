// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "闭关室大门");
	set("long",@LONG
这是闭关室南边，北面有一扇大门。
LONG
);
	set("outdoors", "lingjiu");
	set("exits", ([
		"north" : __DIR__"biguan",
		"south" : __DIR__"xiaodao2",
	]));
	set("objects",([
		__DIR__"npc/shisao" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if (  (dir == "north")
	   && ((string)me->query("family/family_name") != "灵鹫宫")
	   && objectp(present("shi sao", environment(me))) )
	 return notify_fail
		("石嫂伸手拦住你，说道：“对不起，本门重地，请回！”\n");
	return ::valid_leave(me, dir);
}
