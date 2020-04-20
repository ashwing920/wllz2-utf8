//Room: haohanpo.c 好汉坡
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","好汉坡");
	set("long",@LONG
此处连绵十几里山势陡峭，名为好汉坡，山路两旁种满了细竹，翠色
横空景象怡人，不知不觉让你忘记了爬坡的疲劳。坡顶有一座回龙观，是
展望岳顶的最佳去处，但见天柱峰青紫插天，如在眼前，而相去实际上还
有五十里。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"northdown": __DIR__"wdbl",
		"southdown": __DIR__"shanlu1",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
