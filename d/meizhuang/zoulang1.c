// zoulang1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一条长长的走廊，走廊两边是四位庄主中的其他三位平时休息和
练功的地方，这里的左边是书室，右边是画室，三庄主秃笔翁和四庄主丹
青生在闲来无事的时候，便到那里面去挥毫，泼墨。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"shushi",
		"east" : __DIR__"huashi",
		"north" : __DIR__"zoulang2",
		"south" : __DIR__"neiyuan",
	]));
	setup();
	replace_program(ROOM);
}

