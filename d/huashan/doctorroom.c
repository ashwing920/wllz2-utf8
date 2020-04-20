// Room: /d/huashan/doctorroom.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "郎中家");
	set("long", @LONG
这间屋子里住着一位郎中，号称仙医，据说无论遇到什么疑难杂症，
只要到了他手里，都能手到病除。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"road1",
	]));
	set("objects", ([
		__DIR__"npc/doctor" : 1,
	]) );
	set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
