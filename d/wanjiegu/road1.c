// Room: /t/wanjiegu/road1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
这是一条云南的官道，南通大理城，北连中原腹地。大道上人来人往
，热闹非凡。有赶道的，有经商的，也有腰悬利器的武林豪杰。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"road2",
		"south" : "/d/dali/northgate",
	]));

	setup();
	replace_program(ROOM);
}