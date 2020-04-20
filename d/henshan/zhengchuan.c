// Room: /d/henshan/zhengchuan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "正川门");
	set("long", @LONG
正川门是南岳大庙的第三进。院内是玄德宗殿，关圣殿，观音阁等楼
宇。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"south"  : __DIR__"kuixingge",
		"north"  : __DIR__"yubeiting",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

