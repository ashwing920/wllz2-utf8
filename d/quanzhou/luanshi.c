// luanshi.c 乱石岗
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "乱石岗");
	set("long", @LONG
这里树木阴森，砾石嶙峋，坡陡坑深，地势险要，历来是土匪盘据的
地方。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"shisun",
	]));
	set("objects", ([
		__DIR__"npc/tufeitou" : 1,
		__DIR__"npc/tufei1" : 1,
		__DIR__"npc/tufei2" : 2,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
