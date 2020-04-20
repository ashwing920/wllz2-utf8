// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
脚下是一块块大青石板铺设而成的石板路，每块石板都有十尺见方，
巨大无比，沿路都插满了日月教的旗号，由此一直伸延到一座雄伟的楼阁
之前。
LONG
);
	set("exits",([
		"south" : __DIR__"pailou",
		"east" : __DIR__"qiandian",
	]));
	set("objects",([
		__DIR__"npc/shizhe" : 2,
	]));
	setup();
	replace_program(ROOM);
}
