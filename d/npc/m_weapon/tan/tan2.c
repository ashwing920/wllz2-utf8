//tan2.c

inherit ROOM;

void create()
{
	set("short", "嘉兴南湖 ");
	set("long",@LONG
这里是嘉兴南湖水下，四周倒还渐渐有些昏暗了，几道天光从头顶的
潭水中投射下来，此时也不那么瑰丽了，昏沉沉的犹如天边的晚霞。脚下
漆黑一片也不知有些什么。四周的水流也没有那么平静了，似乎在向一个
方向流动着。你不由心中一动：不会有暗流吧！！
LONG
	);
	set("exits", ([
		"up" : __DIR__"tan1",
		"down" : __DIR__"tan3",
	]));
	setup();
	replace_program(ROOM);
}
