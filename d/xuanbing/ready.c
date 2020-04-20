// beidajie1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "小石屋");
	set("long", @LONG
这里是玄冰石室旁边的小石屋，石屋里两边都放着一些石凳，不少前
来参加武林大会的江湖侠客们，正在做参赛的准备。
LONG
);
	set("exits", ([
		"south" : __DIR__"entry",
	]));
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	set("no_beg",1);
	setup();
	replace_program(ROOM); 
}
