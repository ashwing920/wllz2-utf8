
inherit ROOM;

void create()
{
	set("short","长廊");
	set("long", @LONG
这是一条长廊，上面画着江南秀美的工笔画。绿色的柱子朱红色的琉
璃瓦，使得你不由得对江南艺术工匠的创造惊叹不已。在长廊里面，丫鬟
、家丁们走来走去，都忙着自己的事情，西面是一间客厅，南面是长廊的
延伸。
LONG);
	set("exits", ([
		"west" : __DIR__"keting",
		"east" : __DIR__"guifang",
		"north" : __DIR__"c14-3",
		"south" : __DIR__"c14-5",
	]));
	setup();
}
int valid_leave(object me, string dir)
{

	if (dir == "east" && objectp(present("ya huan", environment(me))))
		return notify_fail("夫人吩咐没有重要的事情不要打扰小姐休息。\n");
	return ::valid_leave(me, dir);
}
