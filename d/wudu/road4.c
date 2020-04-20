// Room: /d/wudu/road1. c

inherit ROOM;

void create()
{
	set("short","柳林");
	set("long", @LONG
这是一条湖边的小路，一边是湖泊荡漾，一边是青山依依，微风习面
，好不怡人。眼看西边，只见群柳之中有一座小楼，在蓝天的陪衬下，简
直就是一副美妙的山水画。
LONG
);
	set("outdoors", "wudu");
	set("exits", ([
		"west" : __DIR__"road5",
		"north" : __DIR__"road3",
	]));
	setup();
	replace_program(ROOM);
}

