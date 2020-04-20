// room: /d/xingxiu/tianroad4.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "天山山路");
	set("long", @LONG
这里是天山东麓，山风从山上吹来，你冷得瑟瑟发抖。路边是一片针
叶林。石壁上盛开着一朵洁白的天山雪莲，一个采药人正在采药。东面一
条深涧(valley)挡住了下山的路。
LONG
);
	set("exits", ([
		"westup" : __DIR__"tianroad5"
	]));
	set("objects", ([
		"/d/xingxiu/npc/caiyaoren"  : 1,
		"/d/xingxiu/obj/xuelian" : 1
	]));

	set("item_desc", ([
		"valley" : "深涧有三丈多宽，不过因为这边地势高，应该不难跳(jump)过去。\n"
	]) );
	set("outdoors", "xingxiuhai");
	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="valley" ) {
		   message("vision", me->name() + 
			  "一提气，双足点地跳过了深涧。\n",
		   environment(me), ({me}) );
		   me->move("/d/xingxiu/tianroad3");
		   message("vision", me->name() + 
			  "从深涧上面跳了下来。\n",
		   environment(me), ({me}) );
		   return 1;
	   }
}

