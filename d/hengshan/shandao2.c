// Room: /d/hengshan/huixiantai.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "见性峰山道");
	set("long", @LONG
你走在见性峰山脊小路上，听着山下庙宇的钟鼓，眼前白云漂荡，远
远看到前面就是峰顶了。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"southdown"  : __DIR__"beiyuedian",
		"eastup"	 : __DIR__"square",
	]));

	setup();
	replace_program(ROOM);
}

