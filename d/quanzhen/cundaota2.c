// cundaota2.c 存道塔二层
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "存道塔二层");
	set("long", @LONG
这里是存道塔的二层，塔梯绕着塔内向塔顶延伸。这里空空如也，经
书也许全被全真弟子们借去阅读了。
LONG
	);
	set("exits", ([
		"eastup" : __DIR__"cundaota3",
		"eastdown" : __DIR__"cundaota1",
	]));
	setup();
	replace_program(ROOM);
}
