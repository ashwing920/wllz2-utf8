// 百人道场
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit CHALLENGE_ROOM;

void create()
{
	set("short","百人道场九十四层");
	set("long",@LONG
这里是百人道场第九十四层。身居高处，分外寒冷，可道场中间站着
那中年人，却赤裸着上身，丝毫不觉丁点寒意。壮实的身后背着一把钢刀
，双手插在胸前，用一种轻藐的眼神打量了你一眼。东面有一个出口，通
往道场的休息室。
LONG
);
	set("lvl",94);
	set("exits",([
		"east"  : __DIR__"xiuxishi",
	]));
	set("objects",([
		__DIR__"npc/dizi94":1,
	]));
	::create();
}
