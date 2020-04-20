// lingmu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "古皇陵");
	set("long", @LONG
你一走到这里，突然一片明亮，原来这里竟然是古代蚕丛王的陵墓，
中间停放着一具棺木，棺木的上方悬挂着一颗鹅蛋一般大小的夜明珠，把
这里照得异常明亮，棺木的正中放着一本书，书看起来很陈旧，似乎是一
位前辈异人留下的。 
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"didao5",
		"out" : __DIR__"hupan",
	]));
	set("objects", ([ /* sizeof() == 1 */
		"/clone/book/qunxing-tu.c" : 1,
	]));
	setup();
	replace_program(ROOM);
}

