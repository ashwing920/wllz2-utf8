// gangkou1.c 港口路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "港口路");
	set("long", @LONG
这是用大块花岗石铺成的宽敞大道，平坦结实。路上马车都拉着沉重
的货物南来北往。不少马队都有镖师保护，看来都是价值不菲的货物。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"lingmu",
		"south" : __DIR__"gangkou4",
	]));
	set("objects", ([
		__DIR__"npc/biaotou" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
