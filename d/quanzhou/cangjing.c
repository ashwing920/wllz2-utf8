// cangjing.c 藏经阁
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "藏经阁");
	set("long", @LONG
藏经阁是开元寺的最高处，建在一个小山坡上。阁分两层，阁下有一
小门紧闭。登阁凭栏，看双塔凌空，点坛俯地，饶富诗意。阁上藏经近万
卷。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
		"southdown" : __DIR__"ganlu",
		"northdown" : __DIR__"houshan",
	]));
	set("objects", ([
		__DIR__"npc/monk" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
