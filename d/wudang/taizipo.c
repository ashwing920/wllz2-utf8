//Room: taizipo.c 太子坡
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","太子坡");
	set("long",@LONG
此处地处坡陀之隘，形势险要，相传净乐国太子(少年真武)入山修道
时，曾在此留住读书，故名叫太子坡，好象一朵出水芙蓉，涌出绿波，瓣
萼历历可数。远处峰回路转，忽明忽灭，尽在云雾之中。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"northdown"  : __DIR__"shanlu1",
		"southdown"  : __DIR__"shiliang",
		"east"	 : __DIR__"fuzhenguan",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}