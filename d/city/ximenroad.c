// Room: /city/ximenroad.c
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "西门大道");
	set("long", @LONG
这里是扬州西城门外大道。西通长安城，向东就是西门了。南边，新
开了个武道大会场，每到比武之期，人声鼎沸，你不禁想去见识一下当今
的成名人物。
LONG
);
	set("outdoors", "city");
	set("exits", ([
		"east"  : __DIR__"ximen",
		"west"  : "/d/city4/road1",
	]));
	set("objects", ([
		"/d/center/npc/boy" : 3,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "south") me->set_temp("view_leitai",1);
	return ::valid_leave(me, dir);
}

