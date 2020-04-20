// Room: /d/henshan/shanjian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山涧");
	set("long", @LONG
顺山涧漂流而下，沿溪遍布珍稀树木，泉石，林木，花草及峰峦均极
宜人。涧流至崖折叠飞泄而下，声震山谷。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"down"	 : __DIR__"heishatan",
		"northup"  : __DIR__"fangguangsi",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

