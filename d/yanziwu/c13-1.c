
inherit ROOM;

void create()
{
	set("short","长廊");
	set("long", @LONG
这是一条长廊，上面画着江南秀美的工笔画。绿色的柱子朱红色的琉
璃瓦，使得你不由得对江南艺术工匠的创造惊叹不已。在长廊里面，丫鬟
、家丁们走来走去，都忙着自己的事情，南面是长廊的延伸。
LONG);
	set("exits", ([
		"east" : __DIR__"c13",
		"south" : __DIR__"c13-2",
	]));
	setup();
	replace_program(ROOM);
}
