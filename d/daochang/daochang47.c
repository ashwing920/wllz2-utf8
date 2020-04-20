// 百人道场
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit CHALLENGE_ROOM;

void create()
{
	set("short","百人道场四十七层");
	set("long",@LONG
这里是百人到场第四十七层，只见道场两边各摆着一个兵器架，可兵
器架上却只放着几把锋利的长剑。地上掉落着几断已经断开的兵刃的碎片
，阳光照射进来，耀出道道锋芒。道场中间站着一个身着战甲，手持长剑
的道场弟子，正用一种锐利的眼神盯着你。道场内寂静万分，缕缕轻风飘
过，却倍感阴冷。道场东面有一个出口，通往道场的休息室。
LONG
);
	set("lvl",47);
	set("exits",([
		"east"  : __DIR__"xiuxishi",
	]));
	set("objects",([
		__DIR__"npc/dizi47":1,
	]));
	::create();
}
