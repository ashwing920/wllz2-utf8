
inherit ROOM;

void create()
{
	set("short","长廊");
	set("long", @LONG
这是一条长廊，上面画着江南秀美的工笔画。绿色的柱子朱红色的琉
璃瓦，使得你不由得对江南艺术工匠的创造惊叹不已。在长廊里面，丫鬟
、家丁们走来走去，都忙着自己的事情，不敢有一点怠慢。北西两面面是
长廊的延伸，东面是后院，南面是一间厢房。
LONG);
	set("exits", ([
		 "north" : __DIR__"cl2",
		"east" : __DIR__"houyuan",
		"south" : __DIR__"xiangfang1",
		"west" : __DIR__"c13-1",
	]));
	setup();
	replace_program(ROOM);
}
