//Room: hutouyan.c 虎头岩
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","虎头岩");
	set("long",@LONG
一块巨大的岩石看上去好象一个虎头正张大了血盆大口咆哮，虎身隐
藏在草木丛中。
LONG
);
	set("objects", ([
		__DIR__"npc/laohu" : 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"northdown": __DIR__"wulaofeng",
		"southup"  : __DIR__"chaotiangong",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
