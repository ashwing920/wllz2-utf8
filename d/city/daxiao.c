// daxiao.c

inherit ROOM;

int sos(int,int);
void fresh(object ob);
void create()
{
	set("short", "赌场");
	set("long", @LONG
这里是赌(gamble)「大小」的房间，墙上挂着一块牌子(paizi)。西边
的房间是大赌家玩的地方。
LONG );

	set("exits", ([
		"east" : __DIR__"duchang",
	]));
	setup();
	replace_program(ROOM);
}
