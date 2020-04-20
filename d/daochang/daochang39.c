// 百人道场
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit CHALLENGE_ROOM;

void create()
{
	set("short","百人道场三十九层");
	set("long",@LONG
这里是百人道场的第三十九层，只见道场四周窗户紧闭，密不透风。
道场里死亡般的寂静给人一种莫名的恐惧，只见一个手持长枪，身着百战
道袍的中年人在道场的中间。宁静的气息让你不得不提高警觉，环顾四周
，只有东面的一个出口，通往道场的休息室。
LONG
);
	set("lvl",39);
	set("exits",([
		"east"  : __DIR__"xiuxishi",
	]));
	set("objects",([
		__DIR__"npc/dizi39":1,
	]));
	::create();
}
