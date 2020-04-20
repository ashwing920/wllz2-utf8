//Room: /d/dali/xingyunhu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","星云湖畔");
	set("long",@LONG
星云湖又名小镜湖，方圆有十数里。东靠玉霞山，碧水清澈，风光妩
媚，乃是大理东部名景。明月之夜，皎洁的月光映照湖面，风拂水波，摇
曳生姿，如繁星落入湖中，晶亮如云，故名之。在此远眺湖之东南岸，可
见青青翠竹，似有房舍隐在其中。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	: __DIR__"buxiongbu",
		"eastup"   : __DIR__"yuxiashan",
	]));

	setup();
	replace_program(ROOM);
}

