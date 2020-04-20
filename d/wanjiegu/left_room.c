// Room: /t/wanjiegu/left_room.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "左厢房");
	set("long", @LONG
这是一间普通的房间，里面放着一些日常用品。桌子上放着一壶茶，
还没有冷掉。旁边一个大柜子，里面放着许多衣服。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"bed_room",
		"east" : __DIR__"hall",
	]));

	set("objects", ([
		__DIR__"npc/xier" : 1,
	]));
	setup();
	replace_program(ROOM);
}
