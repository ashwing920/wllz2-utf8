// Room: /d/tangmen/qianliju.c

inherit ROOM;

void create()
{
	set("short","内室");
	set("long", @LONG
这里是神龙教教主洪安通闭关修炼的闭关室，只见闭关室正中挂着一
副人像，人像里画的，正是神龙教教主洪安通。人像前有一个炕头，炕头
上放着一张小木桌，上面放了一些书籍和茶水。
LONG
);
	set("exits", ([
		"up" : __DIR__"houting",
	]));
	set("sleep_room",1);
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
	replace_program(ROOM);
}
