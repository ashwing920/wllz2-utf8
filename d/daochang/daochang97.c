// 百人道场
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit CHALLENGE_ROOM;

void create()
{
	set("short","百人道场九十七层");
	set("long",@LONG
这里是百人道场第九十七层。却见这里门窗紧扣，不见半点阳光。只
有靠南面墙壁上的那盏油灯，闪烁着微弱的光芒。灯影中，一个高大的身
影站在道场的中央，借着微弱的光线，你发现他冷漠无情的脸上，棱角分
明，一股迫人的杀气从他眼神中逼人而来。当你想离开时，却发现这里没
有任何的出路。
LONG
);
	set("lvl",97);
	set("objects",([
		__DIR__"npc/dizi97":1,
	]));
	::create();
}
