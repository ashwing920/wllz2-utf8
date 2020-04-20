
inherit ROOM;

void create()
{
	set("short","夹壁");
	set("long",@LONG
这是书架后面的一道夹壁，要用力推开书架的后面。才有可能出去。
LONG);
	set("exits",([
		"north" : __DIR__"hssg",
	]));
	setup();
}
void init()
{
	add_action("do_push", "push");

}
int do_push(string arg)
{
	object me;
	me = this_player();

	if (arg !="shujia")
		return notify_fail("你要干什么？\n");
	if( arg=="shujia"){
		write("你推了一下书架，书架向两边一移。\n");
		message("vision",me->name() + "身行一闪突然不见了。\n",environment(me), ({me}) );
		me->move(__DIR__"shufang");
		message("vision",me->name() + "走了过来。\n",environment(me), ({me}) );
	}
	return 1;
}
