// suti5.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "苏堤");
	set("long", @LONG
每当盛夏，游客到此纷纷寻荫小息，堤上绿树交柯，鸣蝉噪鼓。北边
是望山桥，南面锁澜桥。
LONG
);
	set("exits", ([
		"north"	 : __DIR__"suti4",
		"south"	 : __DIR__"suti6",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
