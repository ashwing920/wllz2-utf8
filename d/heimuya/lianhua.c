// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "碧血崖");
	set("long", @LONG
这是碧血崖，往东可观黑木崖上秀水玉屏瀑，往西可至黑木崖总舵。
LONG
);
	set("exits",([
		"eastdown" : __DIR__"xianren",
		"west" : __DIR__"yupingpu",
		"east" : __DIR__"wulao",
	]));
	set("objects", ([
		"/d/center/npc/bee":4,
	]));
	set("outdoors","riyue");
	setup();
	replace_program(ROOM);
}
