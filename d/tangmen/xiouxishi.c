inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这是一间很大的休息室，陈设也很简单。靠墙放了十几张竹床。几个
唐门弟子正和衣而卧，满屋子都是呼呼的打酣声。西边有张床是空的，你
蹑手蹑脚地走了过去。
LONG
);
	set("sleep_room",1);
	set("exits", ([
		"south" : __DIR__"lianwuchang",
		"north" : __DIR__"meiyuan1",
	]));
	setup();
	replace_program(ROOM);
}

