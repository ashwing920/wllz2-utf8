// cundaota1.c 存道塔一层
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "存道塔一层");
	set("long", @LONG
这里是存道塔的一层，存道塔是当年全真弟子用来存放经书的地方，
塔不高，是用一块一块的大青石砌起来的。塔中的梯子也是用青石所砌，
据说之所以用石头砌塔是为了避免失火，烧毁了全真教的经书。
LONG
);
	set("exits", ([
		"south" : __DIR__"guozhendian",
		"westup" : __DIR__"cundaota2",
	]));
	setup();
	replace_program(ROOM);
}
