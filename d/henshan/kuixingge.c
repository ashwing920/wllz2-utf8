// Room: /d/henshan/kuixingge.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "奎星阁");
	set("long", @LONG
奎星阁是南岳大庙的第二进。阁为一个大舞台，阁左为鼓亭，右是钟
亭。乡俗年节唱戏，这里总是热闹非凡。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	   "south"  : __DIR__"lingxingmen",
	   "east"   : __DIR__"zhongting",
	   "north"  : __DIR__"zhengchuan",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

