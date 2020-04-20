// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "石道");
	set("long", @LONG
一路往北行，中间仅有一道宽约五尺的石道，两边石壁如墙，一路上
都有日月教徒模样的人物在走动，对往来的路人都严密监视。
LONG
);
	set("exits",([
		"south" : __DIR__"shidao3",
		"north" : __DIR__"shidao2",
	]));
	setup();
	replace_program(ROOM);
}
