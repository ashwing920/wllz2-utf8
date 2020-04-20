// changlang3.c

inherit ROOM;

void create()
{
	set("short","长廊");
	set("long",@LONG
这里一段长廊，两旁是红木廊柱，顶上有很漂亮的漆画和书法。每一
段长廊的书画恰好都组成了一个故事或是一个久远的传说。
LONG
);

	set("exits",([
		"north" : __DIR__"huayuan9",
		"south" : __DIR__"changlang4",
	]));

	setup();
	replace_program(ROOM);
}




