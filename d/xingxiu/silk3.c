// /d/xingxiu/silk3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "丝绸之路");
	set("long", @LONG
这是一条中原和西域之间的商道。南面连绵的祁连山脉在阳光的照射
下好像是一条玉带。东边是中原，西面则通往西域。西南有一座黄沙堆积
形成的山(mount)。
LONG
);
	set("outdoors", "xingxiuhai");
	set("exits", ([
		"southeast" : __DIR__"silk2",
		"west" : __DIR__"silk4",
	]));
	set("objects", ([
		"/d/hangzhou/honghua/huo" :1,
	]));
	set("item_desc", ([
		"mount" : @TEXT
这是一座黄沙堆积形成的山。微风吹动，沙山发出嗡嗡的响声。你不禁对
自然的造物发出由衷的赞叹。
TEXT
	]) );
	setup();
}

void init()
{
	add_action("do_climb", "climb");
}
int do_climb(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="mount") {
		message("vision",
		me->name() + "吭吃吭吃向沙山上爬去。\n",
		environment(me), ({me}) );
		me->move("/d/xingxiu/shashan");
		message("vision",
		me->name() + "从沙山下爬了上来，粘了一身沙子。\n",
		environment(me), me );
		return 1;
	}
}

