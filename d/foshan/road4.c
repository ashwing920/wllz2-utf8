//Room: /d/foshan/road4.c

inherit ROOM;

void create()
{
	set("short","林间道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。这里是广西了。岭南山林茂密
，多产毒虫，各位行路要十分小心。
LONG
);
	set("objects", ([
		__DIR__"npc/snake": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([
		"southwest" : __DIR__"road3",
		"southeast" : __DIR__"road5",
	]));
	setup();
	replace_program(ROOM);
}
