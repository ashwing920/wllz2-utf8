// diziju.c 弟子居
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "小室");
	set("long", @LONG
这是一个小房间，普普通通没什么特殊之处，墙角放着一个大的吓人
的柜子(guizi)！
LONG
);
	set("sleep_room",1);
	set("exits", ([
		"south" : __DIR__"zoulang2",
	]));
	set("item_desc", ([
		"cabinet": "一个柜子，大的吓人。\n"
	]) );
	setup();
}

void init()
{
	add_action("do_open","open");
}

int do_open(string arg)
{
	if( !arg || arg != "guizi" ) {
		return notify_fail("你要拉开什么？\n");
	}

	message_vision("$N把柜子门拉开，进去跳跳。突然出现一个入口。\n", this_player());
	set("exits/down", __DIR__"tulu1");
	remove_call_out("close");
	call_out("close", 8, this_object());

	return 1;
}

void close(object room)
{
	message("vision","柜子门关上了，入口消失。\n", room);
	room->delete("exits/down");
}

