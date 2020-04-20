//Room: sheshenya.c 舍身崖
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","舍身崖");
	set("long",@LONG
这是一处险峻的悬崖峭壁，相传真武帝在此舍身得道。崖上立有铁栅
栏，防止有人自杀步真武帝的后尘。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"east"	 : __DIR__"nanyanfeng",
	]));
	set("outdoors", "wudang");
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
	replace_program(ROOM);
}
