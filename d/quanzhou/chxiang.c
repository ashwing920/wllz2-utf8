// chxiang.c 城隍巷
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "城隍巷");
	set("long", @LONG
一条弯曲狭窄的碎石小路，两旁树木参差，阴暗森冷。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
		"southeast" : __DIR__"citong_n2",
		"northwest" : __DIR__"chmiao",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
