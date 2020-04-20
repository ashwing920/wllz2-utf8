//tangmen.c

inherit ROOM;

void create()
{
	set("short","长廊");
	set("long",@LONG
这里一段长廊，两旁是红木廊柱，顶上有很漂亮的漆画和书法。每一
段长廊的书画恰好都组成了一个故事或是一个久远的传说。这里往南是兵
器库。
LONG
);
	set("exits",([
		"north" : __DIR__"changlang3",
		"south" : __DIR__"bingqiku",
	]));

	setup();
	replace_program(ROOM);
}




