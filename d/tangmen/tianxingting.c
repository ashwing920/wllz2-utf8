
inherit ROOM;

void create()
{
	set("short","天星亭");
	set("long",@LONG
这是一座八角亭，亭内四面有大理石园桌和条凳，供人休息。
LONG
);

	set("exits",([
		"north" : __DIR__"changlang21",
		"south" : __DIR__"changlang20",
	]));

	setup();
	replace_program(ROOM);
}




