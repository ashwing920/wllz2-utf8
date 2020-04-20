// Room: jianbu.c 暗器部
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "暗器部");
	set("long", @LONG
这是武馆的暗器部，由萧飞负责。到处摆着草人靶子，可供练习。
LONG
);

	set("exits", ([
		"south" : __DIR__"zoulang2",
	]));
	set("objects", ([
		__DIR__"npc/xiaofei" : 1,
	]));
	setup();
	replace_program(ROOM);
}
