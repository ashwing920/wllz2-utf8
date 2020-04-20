// Room: /d/hengshan/sanjiaodian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "三教殿");
	set("long", @LONG
这里是全寺最高处的三教殿，也是悬空寺最大的殿宇。三层九脊，全
部由每根插入崖石的木梁承受，真是$HIW$公输天巧$NOR$， 古今奇迹。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"down"   : __DIR__"xuankong1",
	]));
	setup();
	replace_program(ROOM);
}
