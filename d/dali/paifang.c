//Room: /d/dali/paifang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "牌坊");
	set("long", @LONG
这是大理城的牌坊，正中一个牌坊上写着四个金色大字: 圣道广慈。
西边是皇宫，东边是一条青石大道，由于大理国主体民如子，虽皇宫近在
咫尺，但金吾不禁，百姓往来如潮。
LONG
);
	set("outdoors", "dali");
	set("exits", ([
		"east"  : __DIR__"wangfulu",
		"west"  : __DIR__"yujie",
		"south" : __DIR__"taihejiekou",
		"north" : __DIR__"northgate",
	]));
	setup();
	replace_program(ROOM);
}

