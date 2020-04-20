// room: well1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "井底");
	set("long", @LONG
这是在一口枯井的井底。光线极暗，什么也看不清。
LONG
);
	set("exits", ([
		"up" : __DIR__"well",
	]));
	setup();
}

void init()
{
	add_action("do_use", "use");
	add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if (!present("fire", me))  return 0;
	if( arg=="fire" ) {
		 write("你点燃了火折，发现井底什么也没有。\n");
		 return 1;
	}
}

int do_zuan(string arg)
{
	object me;
	me = this_player();

	message_vision("$N像没头苍蝇一样在黑洞洞的井底瞎钻，结果一头撞在井壁的石头上。\n", this_player());
	if(random(2)==1) {
		write("你觉得你晕乎乎的，似乎撞傻了。\n");
	if(me->query_skill("literate", 1) )
		me->set_skill("literate", me->query_skill("literate", 1)-1);
		tell_object(me,"你的读书识字降低了。\n");
	}
		else {
		me->set("qi",10);
		me->unconcious();
	}
	return 1;
}

