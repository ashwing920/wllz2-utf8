// Room: /city/kedian3.c

inherit ROOM;

void create()
{
	set("short", "客店二楼");
	set("long", @LONG
这是一间很大的客房，陈设十分简陋。靠墙放了十几张小木床，不少
客人正和衣而卧，满屋子都是呼呼的打酣声。西边有张床是空的，你蹑手
蹑脚地走了过去。
LONG
);
	set("sleep_room",1);
	set("exits", ([
		"out" : __DIR__"qzkedian2",
	]));
	setup();
}
