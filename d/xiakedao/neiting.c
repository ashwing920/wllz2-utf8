// neiting.c

inherit ROOM;

void create()
{
	set("short", "内厅");
	set("long", @LONG
这是一个石洞，此洞硕大无朋，四周点满了火把，把整个大厅照耀得
十分明亮，中间放着很多石桌和石凳，有很多的江湖人物在石室在参悟武
功之余，在这里休息一会。
LONG );
	set("exits", ([
		"enter" : __DIR__"shihole1",
		"north" : __DIR__"xiuxis2",
		"east"  : __DIR__"shibi",
		"west"  : __DIR__"chashi",
	]));

	set("objects", ([
		__DIR__"npc/shipotian" : 1,
		__DIR__"npc/daoseng": 1,
		__DIR__"npc/dizi": 2,
	]));

	setup();
}

int do_enter(string arg)
{
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="hole" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "丐帮")
		{
			message("vision",
				me->name() + "运起丐帮缩骨功，一弯腰往洞里钻了进去。\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/undersld");
			message("vision",
				me->name() + "从洞里走了进来。\n", environment(me), ({me}) );
			return 1;
		}
		else
			return notify_fail("这么小的洞，你钻得进去吗？\n");
	}
}
