// 百人道场
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit CHALLENGE_ROOM;

void create()
{
	set("short","百人道场二十层");
	set("long",@LONG
这里是百人道场的第二十层。道场四周树立着几根木桩，从木桩的痕
迹和血渍上可以看出，这些木桩是提供给百人道场的弟子平时练功用的。
道场中央站着一个赤手空拳的道场弟子，只见那弟子双拳紧握，细听正发
出阵阵“劈劈啪啪”的声响。后退无路，只有东面的一个出口，是通往道
场的休息室的。如果你想临阵逃脱，就往东面的休息室走吧。
LONG
);
	set("lvl",20);
	set("exits",([
		"east"  : __DIR__"xiuxishi",
	]));
	set("objects",([
		__DIR__"npc/dizi20":1,
	]));
	::create();
}
