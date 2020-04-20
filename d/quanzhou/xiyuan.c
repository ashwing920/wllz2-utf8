// Room: /u/qfy/quanzhou/xiyuan.c

inherit ROOM;

void create()
{
	set("short", "戏院");
	set("long", @LONG
这里是南方戏曲中心，四面八方的戏迷每天都涌入此地一睹为快。戏
院里戏种繁多，曲目精彩。计有南音，梨园戏，提线木偶，高甲戏等饮誉
四方的珍贵艺术。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"southeast" : __DIR__"minzai2",
		"east" : __DIR__"minzai1",
	]));
	setup();
	replace_program(ROOM);
}
