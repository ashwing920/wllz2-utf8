// Room: /d/songshan/qimuque.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "启母阙");
	set("long", @LONG
启母阙在嵩山南麓万岁峰下，是汉代启母庙前的神道阙，和太室阙同
为中岳汉三阙之一。
LONG
);
	set("exits", ([
		"east"  : __DIR__"qimushi",
	]));
	setup();
	replace_program(ROOM);
}

