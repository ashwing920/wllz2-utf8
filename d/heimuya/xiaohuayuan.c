// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "小花园");
	set("long", @LONG
突然闻到一阵花香，胸襟为之一爽，发现是置身于一个极精致的小花
园中，红梅绿竹，青松翠柏，布置得极具匠心，池塘中数对鸳鸯悠游其间
，池旁一个大花圃中尽是深红和粉红的玫瑰，争芳竞艳，娇丽无俦，一堆
假山之中建着间精雅的小舍。
LONG
);
	set("exits", ([
		"up" : __DIR__"dedao",
		"west" : __DIR__"xiaoshe",
	]));
	setup();
	replace_program(ROOM);
}
