// changlang21.c

inherit ROOM;

void create()
{
	set("short","长廊");
	set("long",@LONG
这里一段长廊，两旁是红木廊柱，顶上有很漂亮的漆画和书法。每一
段长廊的书画恰好都组成了一个故事或是一个久远的传说。这里往南就是
天星厅。
LONG
);

	set("exits",([
		"south" : __DIR__"tianxingting",
		"north" : __DIR__"changlang22",
	]));

	setup();
	replace_program(ROOM);
}




