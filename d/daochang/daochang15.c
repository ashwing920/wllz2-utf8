// 百人道场
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit CHALLENGE_ROOM;

void create()
{
	set("short","百人道场十五层");
	set("long",@LONG
你来到了道场的第十五层。道场的地面是由花岗石铺成而成，理应是
十分平坦。可细瞧那地板上，却凹进些许脚印般大小的坑坑，显得崎岖不
平。清风从西面的窗外吹进，荡起道道细腻的尘埃。道场中间有一个身着
百武战袍的弟子正盘膝而坐，双目紧闭。冷漠中，顿觉道道迫人的杀气。
东面有一个出口，通往道场的休息室。如果你不想再打下去了，就往东面
休息室去吧。
LONG
);
	set("lvl",15);
	set("exits",([
		"east"  : __DIR__"xiuxishi",
	]));
	set("objects",([
		__DIR__"npc/dizi15":1,
	]));
	::create();
}
