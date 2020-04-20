// Room: /d/xiangyang/kedian.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "襄阳客栈");
	set("long", @LONG
这是一家对江湖人士来说很有名气的客栈。人们到襄阳来一般都住在
这里，一是便宜，二能听到江湖上的许多事情。近年来，襄阳退敌数十次
，南来北往的人们经过襄阳更是打尖在这儿，顺便拜访一下郭靖等侠衣之
士。
LONG
);
	set("no_sleep_room",1);
	set("valid_startroom", 1);
	set("exits", ([
		"east" : __DIR__"westroad1",
	]));
	set("objects", ([
		__DIR__"npc/wudunru" : 1,
	]));
	setup();
	replace_program(ROOM);
	"/clone/board/kedian6_b"->foo();
}
