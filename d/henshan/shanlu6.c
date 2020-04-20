// Room: /d/henshan/shanlu6.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭绕
，不觉心胸大快。南边山路就是磨镜台和天柱峰。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"southdown": __DIR__"mojingtai",
		"east":	__DIR__"shanlu5",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

