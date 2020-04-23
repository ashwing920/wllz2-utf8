// File(/data/room/avhot/room4.c) of avhot's room
// Create by LUBAN which written by Robert

inherit PRIVATE_ROOM;

void create()
{
	set("short","卧室");
	set ("long", @LONG
这里是主人家的卧室，卧室不是很大，但收拾得十分干净。卧室之中有一张书台，上面零散的放着一些书籍和文房四宝。由此可见，这家
主子也是一个文雅之人。
LONG
);
	set("playerhouse",1);
	set("sleep_room",1);
	set("exits", ([
		"east" : __DIR__"room2",
	]));
	set("owner", "东京热");
	setup();
}
