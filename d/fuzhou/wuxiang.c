inherit ROOM;

void create()
{
	set("short","无相庵");
	set("long","一个小小庵堂。\n");
	set("outdoors", "fuzhou");
	set("exits",([
		"south" : __DIR__"shulin",
	]));
	setup();
	replace_program(ROOM);
}

