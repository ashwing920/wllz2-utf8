// juyan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","巨石");
	set("long", @LONG
你站在巨石之上，放眼眺望，终南山下江山美景尽收眼底，一种豁然
开朗的感觉油然而生。呼呼的冷风从山谷袭来，耳边竟是呼啸的风声。
LONG
);
	set("outdoors", "gumu");
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
}
void init()
{
	add_action("do_jump","jump");
}
int do_jump(string arg)
{
	object me;
	me = this_player();
	
	if(!arg || arg == "" || arg != "down") return 0;
	message_vision("$N飞身跃起，跳了下去，稳稳当当的落在了终南山山峰之上。\n",me);
	me->move(__DIR__"zhufeng");
	return 1;
}
		