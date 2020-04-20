//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

string look_shelf();
#include <ansi.h>
#define STORY_TOC   "/doc/story/toc"
#define POEM_DIR "/doc/story/"

inherit ROOM;

void create()
{
	set("short", "性文学图书馆");
	set("long", @LONG
这是一间极为隐蔽的图书收藏室。你可以用(kan) 来阅读书架上的小
说。不过你必须年满十八岁哦！
LONG
);
	set("item_desc", ([
		"shelf" : (: look_shelf :),
		"书架" : (: look_shelf :),
	]));
	set("exits", ([
		"south" : __DIR__"yihongyu",
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
	object me;
	me = this_player();

	if( me->query("age") <= 18 )
		return notify_fail("你还未满十八岁，看这些书会影响你身心健康的。\n");

	if (arg == "" || file_size(POEM_DIR + arg) <= 0)
		return notify_fail("我们没有这本书。\n");

	switch (MONEY_D->player_pay(this_player(), 20000)) {
		case 0:
		return notify_fail("穷光蛋，一边呆着去！\n");
		case 2:
		return notify_fail("您的零钱不够了，银票又没人找得开。\n");
	}

	log_file("LIBRARY", sprintf("%s read %s.\n", this_player()->query("name"), arg));
	message("channel:rumor",HIM"【武林传奇】某人："+ me->name() +" 拿起一本"HIR + arg +"，津津有味的看了起来。\n"NOR,users());
	this_player()->start_more(read_file(POEM_DIR + arg));
	return 1;
}
