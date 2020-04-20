// duxiang.c 都督巷
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "都督巷");
	set("long", @LONG
这是泉州的一条小巷，清净整洁。远远可见巷底红墙高砌，把守森严
，显然不是普通的住家。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"citong_n1",
		"east" : __DIR__"dufu",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
