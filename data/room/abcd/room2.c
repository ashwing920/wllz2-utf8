// File(/data/room/abcd/room2.c) of abcd's room
// Create by LUBAN which written by Robert

inherit PRIVATE_ROOM;

void create()
{
	set("short","卧室");
	set ("long", @LONG
这是一间不大的屋子，透过精致的花木格窗户依稀可以看到院子的景观。屋角房着一张床，看上去非常舒适。
LONG
);
	set("sleep_room",1);
	set("playerhouse",1);
	set("room_owner_id","abcd");
    set("objects", ([
            "/adm/npc/obj/xiang" : 1,
    ]));
	set("exits", ([
		"east" : __DIR__"room1", //客厅
	]));
	setup();
}
