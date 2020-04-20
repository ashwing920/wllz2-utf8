
inherit ROOM;

void create()
{
	set("short","岸边");
	set("long",@LONG
从小舟下来，你踏上了小岛的岸边，只见三面全是花的世界。落第秀
才，十八学士，十三太保，八仙过海，风尘三侠等数种名贵的茶花萦绕在
你的周围，你已经身陷花丛中，如果不仔细的辨别方向，很难能够走出去。
LONG);
	set("outdoors","yanziwu");
	set("exits",([
		"south" : __DIR__"hc",
		"east" : __DIR__"hc1",
		"west" : __DIR__"hc2",
	]));
	setup();
	replace_program(ROOM);
}
