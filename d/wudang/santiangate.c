//Room: santiangate.c 三天门
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","三天门");
	set("long",@LONG
这里是登山石阶的尽头“三天门”，再往上走就是武当绝顶了。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"northdown": __DIR__"ertiangate",
		"southup"  : __DIR__"jinding",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
