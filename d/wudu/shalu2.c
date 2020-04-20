// Room: /d/wudu/road1. c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条崎岖的山路，十分不好走，两边树林密布，抬头看去只见一
座巨大的峭壁拦在前面，真不知道是否有路可以走。
LONG
);
	set("outdoors", "wudu");
	set("exits", ([
		"westup" : __DIR__"qiaobi1",
		"eastdown" :__DIR__"shalu1",
	]));
	setup();
	replace_program(ROOM);
}

