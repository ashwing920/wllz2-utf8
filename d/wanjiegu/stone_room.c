// Room: /t/wanjiegu/stone_room.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "石屋");
	set("long", @LONG
一间用花岗岩砌成的房子，坚固无比。南面有一个小孔，西边有一张
小床，屋内光线黑暗，又有些潮湿。一人女子正坐在床上不停地喘气，身
上的衣服都被汗水湿透了。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"backyard",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/mu" : 1,
	]));
	setup();
	replace_program(ROOM);
}
