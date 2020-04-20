
inherit ROOM;

void create()
{
	set("short", "私塾");
	set("long", @LONG
这里是慕容家里的书堂，为了让家里的孩子能够得到很好的教育，慕
容家特意聘请了一位私塾先生来讲课。
LONG);

	set("exits", ([
		"south" : __DIR__"shufang",
	]));
	set("objects", ([
		__DIR__"npc/xiansheng": 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	me->delete_temp("mark/朱", 0);
	return 1;
}
