// xilingqiao.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "西泠桥");
	set("long", @LONG
西泠桥衔结孤山，跨过里西湖。桥的东南边是孤山。北边则是一条青
石大道。
LONG
);
	set("exits", ([
		"southeast" : __DIR__"gushan",
		"north"	 : __DIR__"road7",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
