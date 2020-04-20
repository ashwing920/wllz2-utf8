// Room: /d/henshan/yushulou.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "御书楼");
	set("long", @LONG
御书楼为南岳庙历代藏书之处，天子御赐，贤达乐捐，这里早已洋洋
大观。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"south"  : __DIR__"jiayingmen",
		"north"  : __DIR__"dadian",
	]));
	setup();
	replace_program(ROOM);
}

