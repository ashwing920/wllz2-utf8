//Room: wulaofeng.c 五老峰
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","五老峰");
	set("long",@LONG
只见五座奇峰突兀，惊险无比，行人多不敢放胆在此玩赏风景。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"northdown": __DIR__"sanlaofeng",
		"southup"  : __DIR__"hutouyan",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
