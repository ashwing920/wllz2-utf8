// shuyuan2.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

string look_shelf();

#define STORY_TOC "/doc/story/toc"
#define POEM_DIR "/doc/story/"
inherit ROOM;

void create()
{
	set("short","书院书库");
	set("long", @LONG
这里是书院的图书馆，窗明几净，一尘不染。壁上的书架( shelf)堆
满一些出于明家手笔的珍贵书籍。你可以使用( kan)来阅读这些古老的故
事。
LONG);

	set("item_desc", ([
		"shelf": (: look_shelf :),
	]));
	set("exits", ([
		"down" : __DIR__"shuyuan",
	]));

	setup();
}

void init()
{
	add_action("do_kan", "kan");
}

string look_shelf()
{
	this_player()->start_more(read_file(STORY_TOC));
	return "\n";
}

int do_kan(string arg)
{
	object me=this_player();
	if (arg == "" || file_size(POEM_DIR + arg) <= 0)
		return notify_fail("我们没有这本书。\n");

	log_file("POEM", sprintf("%s read %s.\n", me->query("name"), arg));
	me->start_more(read_file(POEM_DIR + arg));
	return 1;
}

