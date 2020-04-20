// senlin5.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "百木园");
	set("long", @LONG
这里是梅庄的百木园，你一走到这里，就象走到了一个连绵无尽的小
森林一样，这里无数的松树，柏树，白杨，还有很多叫不出来名字的异种
苗木，你走在其中，只想把这片树林尽情的欣赏一遍，永不出去才好。
LONG
);
	set("exits", ([ /* sizeof() == 8 */
		"southeast" : __DIR__"senlin4",
		"northeast" : __DIR__"senlin2",
		"west" : __DIR__"senlin2",
		"east" : __DIR__"senlin2",
		"north" : __DIR__"senlin3",
		"south" : __DIR__"senlin5",
		"northwest" : __DIR__"senlin4",
		"southwest" : __DIR__"senlin6",
	]));
	set("outdoors", "meizhuang");
	setup();
	replace_program(ROOM);
}

