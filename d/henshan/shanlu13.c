// Room: /d/henshan/shanlu13.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕
，不觉心胸大快。东北方就是南天门了，高高矗立在西北方的就是衡山五
峰之一的芙蓉峰。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"northeast"  : __DIR__"nantian",
		"southeast"  : __DIR__"shanlu5",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

