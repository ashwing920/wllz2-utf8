// Room: /d/wudu/caofang1.c

inherit ROOM;

void create()
{
	set("short","厢房");
	set("long", @LONG
一间十分简陋的草房，支着一张破木床，家具都是十分的破旧光线很
暗，你只觉的四周透着一股邪气。
LONG
);
	set("exits", ([
		"north" : __DIR__"caofang",
		"west" : __DIR__"houyuan",
	]));
	set("objects", ([
		CLASS_D("wudu") + "/hehongyao" : 1
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;

	if(mapp(myfam = me->query("family")) && myfam["family_name"] != "五毒神教"
	&& dir == "west" && present("he hongyao", environment(me)))
	   return notify_fail("何红药拦住你说道：寻常人家的小院没什么好看的，这里荒山之中。虫兽甚多，你还是尽快离开吧。\n");
	
	return ::valid_leave(me, dir);
}
