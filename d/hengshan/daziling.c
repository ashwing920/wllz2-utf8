// Room: /d/hengshan/daziling.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "大字岭");
	set("long", @LONG
大字岭是入恒山必由之路。石壁上镌有恒宗二字，高可两丈，笔力遒
劲，气势雄浑。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"west"	  : __DIR__"yunge",
		"northeast" : __DIR__"hufengkou",
	]));
	set("outdoors", "hengshan");
	setup();
	replace_program(ROOM);
}

