// Room: /d/wudu/hsonglin3

inherit ROOM;

void create()
{
	set("short", "毒龙洞" );
	set("long", @LONG
这里黑乎的不见一点光亮，你什么都看不见。
LONG
);
	set("outdoors", "wudu");
	set("exits", ([
		"out" : __DIR__"dulongdong1",
	]));
	setup();
	replace_program(ROOM);

}
