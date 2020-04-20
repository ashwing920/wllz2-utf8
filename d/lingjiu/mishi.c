// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这是个阴暗的密室，墙上的油灯发出昏暗的黄光。
LONG
);
	set("exits", ([
		"up" : __DIR__"huayuan",
	]));
	set("objects",([
		"/clone/book/zhemei_book1" : 1,
		"/clone/book/zhemei_book2" : 1,
		"/clone/book/liuyang_book1" : 1,
		"/clone/book/liuyang_book2" : 1,
		"/clone/book/qijianpu" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{

	if((dir=="up") &&
		( present("zhangfa tu1",me)
		|| present("zhangfa tu2",me) 
		|| present("shoufa tu1",me) 
		|| present("shoufa tu2",me) 
		|| present("pu",me) ))
		return notify_fail("你带着秘籍这样大摇大摆的离开，你也不怕被人家逮住？\n");

	return ::valid_leave(me, dir);
}
