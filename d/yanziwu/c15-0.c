
inherit ROOM;

void create()
{
	set("short","长廊");
	set("long", @LONG
这是一条长廊，上面画着江南秀美的工笔画。绿色的柱子朱红色的琉
璃瓦，使得你不由得对江南艺术工匠的创造惊叹不已。在长廊里面，丫鬟
、家丁们走来走去，都忙着自己的事情，不敢有一点怠慢。长廊西面是书
房，南面是长廊的延伸。
LONG);
	set("exits", ([
		"south" : __DIR__"c15-1",
		"east" : __DIR__"fanting1",
		"west" : __DIR__"shufang",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "east" && me->query("family/family_name") != "慕容世家"
	&& objectp(present("guan jia", environment(me))))
		   return notify_fail("管家喝道：“到慕容山庄不要乱闯”！\n");
	return ::valid_leave(me, dir);
}
