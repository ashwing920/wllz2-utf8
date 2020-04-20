// yandong.c
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "岩洞");
	set("long", @LONG
这里四周没有丝毫的光亮，每前进一步，都要先试探个虚实，但是却
觉得脚下平整，便似走在石板路上一般，只见道路不断地往下倾斜，越走
越低。
LONG
);
	set("exits", ([
		"north" : __DIR__"damen",
		"out" : __DIR__"hubian",
	]));

	setup();
	replace_program(ROOM);
}
