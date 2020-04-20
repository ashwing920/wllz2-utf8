// Room: /d/hengshan/yunge.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "云阁虹桥");
	set("long", @LONG
过完栈道，就到云阁虹桥。前往恒山主峰见性峰，都要在这里跨过唐
峪河。拱桥卧波，水天亮丽，倍觉胸襟舒畅。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"east"	  : __DIR__"daziling",
		"northdown" : __DIR__"zhandao",
	]));
	set("objects", ([
		__DIR__"npc/zhi" : 1,
	]));
	set("outdoors", "hengshan");

	setup();
	replace_program(ROOM);
}

