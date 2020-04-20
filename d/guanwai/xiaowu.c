//guanwai/xiaowu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "小茅屋");
	set("long", @LONG
这是一座用长白山松木垒成的小屋，屋内打扫的很干净。四周的墙壁
上挂满了兽皮和雪橇，一张小小的桌旁坐着一个英俊少年。
LONG
);
	set("exits", ([
		"south" : __DIR__"baihe",
	]));
	set("objects", ([
		__DIR__"npc/hufei" : 1,
	]));
	set("no_beg",1);
	set("no_fight",1);
	setup();
	replace_program(ROOM);
}

