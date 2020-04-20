// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "一品崖");
	set("long", @LONG
走过五老峰，前面是一道要命的峭壁“一品崖”，呼呼的山风阵阵吹
来，生怕鞋一滑被吹落下去，那就不大好赏景了。
LONG
);
	set("exits",([
		"south" : __DIR__"wulao",
	]));
	set("objects", ([
		__DIR__"npc/wolf": 2,
	]));
	set("outdoors","riyue");
	setup();
	replace_program(ROOM);
}
