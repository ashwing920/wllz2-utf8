
inherit ROOM;

void create()
{
	set("short","岸边");
	set("long",@LONG
远远看去，只见一个小洲上八九间房间，其中两间是楼房。阁宇中隐
，约露出一个牌坊「$HIY$听香水榭$NOR$」。
LONG);
	set("outdoors","yanziwu");
	set("exits",([
		"south" : __DIR__"shuixie",
	]));
	setup();
	replace_program(ROOM);
}
