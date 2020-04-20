// Room: /d/tangmen/qianliju.c

inherit ROOM;

void create()
{
	set("short","内室");
	set("long", @LONG
你来到了一间布置典雅的内室，一副山水画挂在内室北面的墙壁上，
墙边上放着一张床，每隔几个月，唐老太便会到这里，不吃不喝，闭关修
炼。
LONG
);
	set("exits", ([
		"east" : __DIR__"qianliju",
	]));
	set("sleep_room",1);
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
	replace_program(ROOM);
}
