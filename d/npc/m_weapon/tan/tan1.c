//tan1.c

inherit ROOM;

void create()
{
	set("short", "嘉兴南湖 ");
	set("long",@LONG
这里是嘉兴南湖水下，四周倒还比较明亮，几道天光从头顶的潭水中
投射下来，显得十分美丽。脚下漆黑一片也不知有些什么。你不由对自己
说......
LONG
	);
	set("exits", ([
		"up" : "/d/quanzhou/nanhu",
		"down" : __DIR__"tan2",
	]));
	setup();
	replace_program(ROOM);
}
