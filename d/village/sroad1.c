// Room: /d/village/sroad1.c

inherit ROOM;

void create()
{
	set("short", "碎石路");
	set("long", @LONG
这是一个宁静的小村子，稀稀落落的分布着几十间土坯泥房，看来村
中人家不多，而且大都生活很艰辛。一条碎石路，往北通向村子的中心，
往南就是出村的路了。
LONG );
	set("exits", ([
		"north" : __DIR__"sroad2",
		"south" : __DIR__"sexit",
	]));

	set("outdoors", "xxx");
	set("objects", ([
		"/d/center/npc/girl": 1,
		"/d/center/npc/boy": 2,
	]), );

	setup();
	replace_program(ROOM);
}

