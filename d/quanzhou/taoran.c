// taoran.c 淘然茶居

inherit ROOM;

void create()
{
	set("short", "淘然茶居");
	set("long", @LONG
这是专供品尝和销售茶叶的店铺，店里清香四溢进门就有心旷神怡之
感。墙上有一价目表(sign)。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"xinmen",
	]));
	set("objects", ([
		__DIR__"npc/taolao" : 1,
	]));
	set("item_desc",([
		"sign" : "乌龙茶  ：三十文铜板\n"
			 "铁观音  ：三十文铜板\n"
			 "龙井茶  ：三十文铜板\n"
			 "茉莉花茶：三十文铜板\n"
			 "香片    ：三十文铜板\n"
	]));
	setup();
	replace_program(ROOM);
}
