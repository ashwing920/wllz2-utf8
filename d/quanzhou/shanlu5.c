// shanlu1.c 山路

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是清源山区的碎石小径，曲折蜿蜒，两旁林木茂盛，遮天蔽日。满
径落叶，柔软稀松。虫鸟啾啾。凉风习习。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"northup" : __DIR__"cien",
		"southdown" : __DIR__"shanlu6",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
