// Room: /d/mingjiao/nanshe.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "天门男舍");
	set("long", @LONG
走进这间男舍，一阵汗臭酒熏扑面，根本挥赶不去。几个五大三粗汉
子光脚神气赳赳，豪迈异常地喊你入席。桌上酒水淋漓，杯盘狼籍，显然
都喝得差不多了。
LONG
);
	set("exits", ([
		"out" : __DIR__"mjtianmen1",
	]));
	set("sleep_room", 1);
	setup();
	replace_program(ROOM);
}
