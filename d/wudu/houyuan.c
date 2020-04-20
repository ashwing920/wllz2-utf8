// Room: /d/wudu/caofang1.c

inherit ROOM;

void create()
{
	set("short","后院");
	set("long", @LONG
这是一个普通的院子，稀疏的种了点蔬菜，一角堆放着许多干草，几
只小鸡在四处找虫子，看起来没什么特别的。
LONG
);
	set("item_desc",([
		"干草" : "一堆干草，看上去经常有人动过，你不由想扒(dig)开看看",
	]));
	set("exits", ([
		"east" : __DIR__"caofang1",
	]));
	setup();
}
int init()
{
	add_action("do_dig", "dig");
	add_action("do_dig", "扒");
	add_action("do_dig", "ba");
}
int do_dig( string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" || arg != "干草") 
		return notify_fail("你想扒什么？\n");
	
	if(query("baed"))
		return notify_fail("干草堆已经被人扒开，露出了一个洞口。\n");

	message_vision("$N把干草扒开，露出了一个洞口。\n",me);
	set("exits/enter", __DIR__"midao1");
	remove_call_out("close_door");
	call_out("close_door", 10);
	set("baed",1);
	return 1;
}

void close_door()
{
	delete("exits/enter");
	delete("baed");
}       
