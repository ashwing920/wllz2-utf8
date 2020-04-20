// houmen.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","后门");
	set("long",@LONG
这是个山庄的后门。这里有捷径可以通向星宿海。
LONG
);
	set("exits",([
		"north" : "/d/xingxiu/xxh1",
		"south" : __DIR__"tuyuan",
	]));
	set("objects", ([
		__DIR__"npc/menwei" : 1 ,
	]));
	set("outdoors", "baituo");
	setup();
}

int valid_leave(object me, string dir)
{

	if((dir == "south")
		&& ((int)me->query("shen") > 3000)
		&& objectp(present("men wei", environment(me)))) 
	return notify_fail("门卫把手一拦：你这种正派人物，老子一看就恶心，快滚！\n");
	return ::valid_leave(me, dir);
}
