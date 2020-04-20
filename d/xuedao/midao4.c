// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "暗道");
	set("long", @LONG
这是血刀门的暗道，阵阵湿气从北边吹来，你听到周围有男女荡笑的
声音。
LONG
);
	set("exits", ([
		"north" : __DIR__"yinku",
		"south" : __DIR__"midao3",
		"west" : __DIR__"midao5",
		"east" : __DIR__"midao2",
	]));
	setup();
	replace_program(ROOM);
}

