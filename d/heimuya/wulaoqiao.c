// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "五老峰峭壁");
	set("long", @LONG
这是五老峰峭壁，山风“呼呼”地吹过耳边，此地不宜久留。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"down" : __DIR__"wulaoshan",
	]));
	set("objects", ([
		__DIR__"npc/houzi2": 1,
		__DIR__"npc/xiaohou": 1,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	if(dir == "down" && this_player()->query("dex")<30)
		return notify_fail("下边杂草丛生，根本看不到路，小心一失足成千古恨。\n");
	return ::valid_leave(me, dir);
}
void init()
{
	add_action("do_climb", "hua");
}
int do_climb(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="yeteng") {
		message("vision",
		me->name() + "双手抓住野藤，漫漫滑下去。\n",
		environment(me), ({me}) );
		me->move(__DIR__"wulao");
		message("vision",
		me->name() + "从下面顺着野藤爬了上来。\n",
		environment(me), me );
		return 1;
	}
}
