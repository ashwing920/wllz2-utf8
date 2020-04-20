// quyuanbei.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "曲院风荷");
	set("long", @LONG
跨过小拱桥，迎面有一亭院，旁边立着石碑，上题“曲院风荷。”往
东是回苏堤。
LONG
);
	set("exits", ([
		"east"	 : __DIR__"suti2",
		"enter"	: __DIR__"quyuanfenghe",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
