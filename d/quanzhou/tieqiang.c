// Room: /d/quanzhou/tieqiang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "铁枪庙");
	set("long", @LONG
这铁枪庙祀奉的是五代时名将铁枪王彦章。庙旁有座高塔，塔顶群鸦
世代为巢，当地乡民传说铁枪庙的乌鸦是神兵神将，向来不敢侵犯，以致
生养繁殖，越来越多。案桌下有个小洞(dong)。
LONG
);
	set("exits", ([
		"west" : __DIR__"jxnanmen",
		"north" : __DIR__"nanhu",
	]));
	set("item_desc", ([
		"dong" : "一个在案桌下隐藏得很好的土洞。\n",
	]));
	set("objects", ([
		__DIR__"npc/wuya": 4
	]));
	set("outdoors", "quanzhou");
	setup();
}

void init()
{
	add_action("do_enter", "enter");
	add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me;
	mapping fam;

	me = this_player();
	if( !arg || arg=="" ) return 0;
	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "丐帮" ) 
		{
			message("vision",
				me->name() + "运起丐帮缩骨功，一弯腰往洞里钻了进去。\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/underqz");
			message("vision",
				me->name() + "从洞里走了进来。\n",
				environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("这么小的洞，你钻得进去吗？\n");
	}
}
