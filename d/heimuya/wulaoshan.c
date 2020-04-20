// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "五老峰山洞");
	set("long", @LONG
这是五老峰半山腰的山洞，山洞里满是尘土，洞口边有野藤(yeteng)
摆晃，倒象是有人住过一般。
LONG
);
	set("item_desc", ([
		"yeteng" : "这倒是一条多年老野藤，还蛮结实的。\n",
	]));
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
	if( arg=="yeteng") {
		message("vision",
		me->name() + "双手抓住野藤，脚一点地就爬了上去。\n",
		environment(me), ({me}) );
		me->move(__DIR__"wulaoqiao");
		message("vision",
		me->name() + "从上面顺着野藤滑了下来。\n",
		environment(me), me );
		return 1;
	}
}
