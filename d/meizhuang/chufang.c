// chufang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
你顺着香味走到了梅庄的厨房，一位厨师正站在灶台后面笑眯眯的看
着你，他手上拿着一柄铁勺，用力的把锅里煮着的一大堆食物搅匀，梅庄
的弟子们如果饿了，就到这里来问这位厨师能不能吃饭，一般来说，他们
都不会遭到拒绝的。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"zoulang3",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/chushi" : 1,
	]));
	setup();
	replace_program(ROOM);
}

