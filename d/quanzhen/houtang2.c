// houtang2.c 后堂二进
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "后堂二进");
	set("long", @LONG
这里是全真教弟子平常研讨武功的地方，这个堂不大，由于经常要在
这里演武，索性连桌椅也全都靠到墙边去了，这样腾出了一大片空地来。
LONG
);
	set("exits", ([
		"east" : __DIR__"houtang3",
		"west" : __DIR__"houtang1",
		"south" : __DIR__"wuchang1",
		"north" : __DIR__"liangong",
	]));

	setup();
	replace_program(ROOM);
}
