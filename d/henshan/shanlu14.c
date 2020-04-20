// Room: /d/henshan/shanlu14.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕
，不觉心胸大快。山路转过芙蓉峰，西面远远看到藏经阁，东南方向通往
南天门。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"west"	   : __DIR__"cangjingdian",
		"southeast"  : __DIR__"nantian",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

