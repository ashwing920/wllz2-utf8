// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "牌楼");
	set("long", @LONG
这里是一座牌楼，东面是日月教教徒的休息室，南面是一个打铁铺，
北面是一条长长的石板路，也不知通向什么地方。
LONG
);
	set("exits",([
		"east" : __DIR__"xiangfang",
		"south" : __DIR__"datiepu",
		"west" : __DIR__"shiwu",
		"north":__DIR__"shibanlu",
	]));
	set("objects", ([
		__DIR__"npc/shizhe": 4,
	]));
	setup();
	replace_program(ROOM);
	"/clone/board/riyue_b"->foo();

}
