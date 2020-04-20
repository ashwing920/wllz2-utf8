// shantang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这是间宽敞的厨房，厨师们正在准备饭菜。整个房间弥漫着令人垂涎
欲滴的菜香。墙上光秃秃的。什么也没有，你大可(order)一份。
LONG
);
	set("exits",([
		"west" : __DIR__"lwchang1",
	]));
	setup();
}

void init()
{
	add_action("do_order","order");
}

int do_order(string arg)
{
	object me=this_player();
	object food;
	object water;

	if (arg) return notify_fail("这样东西这里没有啊。\n");
	if (me->query("family/family_name") != "血刀门"){
		message_vision("一凶僧冲出来，瞪了$N一眼：“你哪混的！敢混饭吃！”\n",me);
		return 1;
	}

	if ((present("bowl",this_player()) || present("rice",this_player())))
		  message_vision("一凶僧冲出来，瞪了$N一眼：“还没吃完又想要！”\n",me);
	else
	{
		message_vision("一凶僧厨房出来，把一盘肉干和一碗奶茶丢给$N。\n",me);
		food=new(__DIR__"obj/rougan");
		water=new(__DIR__"obj/naicha");
		food->move(me);
		water->move(me);
	}
	return 1;
}

int valid_leave(object me,string dir)
{
	me=this_player();
	if(( dir=="west" || dir=="east")
	&& (present("wan",this_player()) || present("gan",this_player())))
		 return notify_fail("一凶僧说道：想拿走，没门。\n");
	return ::valid_leave(me,dir);
}
