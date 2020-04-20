// shidong.c
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "石洞");
	set("long", @LONG
这是一个比较大的圆形石洞，光亮从左边的窗口透了过来，细看那窗
的时候，发现原来是镶在石壁上的一块大水晶透过水晶向外看去，只见鱼
虾水族来回游动，原来你竟处身水底之中！
LONG
);
	set("exits", ([
		"south" : __DIR__"damen",
		"north" : __DIR__"shishi3",
		"east" : __DIR__"shiji2",
		"west" : __DIR__"shiji1",
	]));

	setup();
	replace_program(ROOM);
}
