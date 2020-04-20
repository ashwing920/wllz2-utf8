//Room: sanlaofeng.c 三老峰
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","三老峰");
	set("long",@LONG
只见三座奇峰突兀，惊险无比，行人多不敢放胆在此玩赏风景。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"northdown": __DIR__"wuyaling",
		"southup"  : __DIR__"wulaofeng",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
