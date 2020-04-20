// Room: /d/tangmen/qianliju.c

inherit ROOM;

void create()
{
	set("short","内室");
	set("long", @LONG
你来到了王府的内室当中，只见内室宽敞明亮，内室正中摆着一面屏
风，屏风后有一张红木做的木床，床边上有一张小书台，上面放着一些书
籍。
LONG
);
	set("exits", ([
		"out" : __DIR__"neitang",
	]));
	set("sleep_room",1);
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
	replace_program(ROOM);
}
