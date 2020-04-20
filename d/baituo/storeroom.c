// storeroom.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "储藏室");
	set("long",@LONG
这是一个储藏室，四周密不透风。只有关闭着的大门(door)。
LONG
);
	set("item_desc" , ([
		"door" : "一扇木门，也许能打开。\n",
	]) );
	setup();
}

void init()
{
	add_action("do_open","open");
}

int do_open(string arg)
{
	object me=this_player();
	object room;

	if( !arg|| arg!="door")
		return notify_fail("你要开什么？\n");

	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if(!( room = find_object(__DIR__"yuanzi")) )
		room = load_object(__DIR__"yuanzi");

	if(!objectp(room)) 
		return notify_fail("ERROR:not found 'yuanzi.c' \n");

	if(room->query_temp("lock")==1)
		return notify_fail("门已经从外面锁住了。\n");

	message_vision("$N轻轻推开门，走了出去，随手把门掩了起来。\n",me);
	message("vision", "有人走了出来，随手把门掩上了。\n",room);
	me->move(room);

	return 1;
}
