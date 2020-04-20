// huangniling.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "黄泥岭");
	set("long", @LONG
一条黄土路弯弯曲曲，四周非常的安静。偶而才看见些游人匆匆而过
。南北分别是下山的路。
LONG
);
	set("exits", ([
		"southdown"   : __DIR__"maojiabu",
		"northdown"   : __DIR__"road3",
	]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
