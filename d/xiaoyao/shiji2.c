// shiji2.c
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "石级");
	set("long", @LONG
这是一段长长的石级，四周由于缺乏光亮，难免有点阴深深的感觉，
石级向着东西两面伸展，一眼望去，不可以望到尽头。
LONG
);
	set("exits", ([
		"east" : __DIR__"shishi2",
		"west" : __DIR__"shidong",
		"north" : __DIR__"fangjian2",
	]));

	setup();
	replace_program(ROOM);
}
