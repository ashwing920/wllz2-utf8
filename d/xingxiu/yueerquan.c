// Room: /d/xingxiu/yueerquan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "月儿泉");
	set("long", @LONG
出乎你的意料之外，在沙漠中竟然有泉水。一泓清澈的泉水形成一个
月牙的形状，因而得名月儿泉。 南面是一片峭壁(cliff)，东边传来嗡嗡
的声响。
LONG
);
	set("resource/water", 1);
	set("exits", ([
		"east" : __DIR__"shashan",
	]));
	set("item_desc", ([
		"cliff" : "峭壁上似乎有一个洞(hole)。\n"
	]) );
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}
int do_enter(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="hole" ) {
		if ( me->query_encumbrance() * 100 / me->query_max_encumbrance() < 20) {
			 message("vision", me->name() + "一纵身跃进了洞里。\n",
			environment(me), ({me}) );
			 me->move("/d/xingxiu/mogaoku");
			 message("vision", me->name() + "从洞外跳了进来。\n",
			environment(me), ({me}) );
			 return 1;
		}
		else {
			 write("你身上背的东西太重，洞口又太高，你够不着。\n");
			 return 1;
		}
	}
}

