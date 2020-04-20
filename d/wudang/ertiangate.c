//Room: ertiangate.c 二天门
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","二天门");
	set("long",@LONG
这里是“二天门”，金光灿灿的金顶就在眼前了。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"northdown": __DIR__"toutiangate",
		"southup"  : __DIR__"santiangate",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
