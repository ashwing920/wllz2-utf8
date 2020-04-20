// neiyuan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "内院");
	set("long", @LONG
这里是梅庄的内院，从这里走过去就可以找到四位庄主，这里似乎非
常安静，可以听见落叶触地的声音，但又似乎非常吵闹，经常可以听到嘈
杂的琴声，但这琴声又可以将你的心弦打乱，你真不知道该怎么形容这个
地方。有一位壮年的汉子，腰悬宝剑守在院门口。
LONG
);
	set("outdoors", "meizhuang");
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"senlin1",
		"north" : __DIR__"zoulang1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/huyuan.c" : 1,
	]));
	setup();
	replace_program(ROOM);
}

