//Room: toutiangate.c 头天门
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","头天门");
	set("long",@LONG
只见有石梯无数通往山巅，一座石坊上写着“头天门”三个大字，这
是攀登武当绝顶天柱峰的起点。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"north"	: __DIR__"huixianqiao",
		"southup"  : __DIR__"ertiangate",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
