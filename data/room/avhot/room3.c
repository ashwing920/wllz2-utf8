// File(/data/room/avhot/room3.c) of avhot's room
// Create by LUBAN which written by Robert

inherit PRIVATE_ROOM;

void create()
{
	set("short","偏厅");
	set ("long", @LONG
这里是大厅西面的偏厅，是主人家用来进餐时所用。偏厅之中有一张圆桌，上面还放着一副茶具。一个小丫环正站在圆桌旁边，小心翼翼
的擦拭着。
LONG
);
	set("playerhouse",1);
	set("objects",([
		"/d/room/npc/yahuan":1,
	]));
	set("exits", ([
		"east" : __DIR__"room1",
	]));
	set("owner", "东京热");
	set("room_owner_id","avhot");
	setup();
}
