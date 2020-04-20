// 百人道场
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit CHALLENGE_ROOM;

void create()
{
	set("short","百人道场六十一层");
	set("long",@LONG
这里是百人道场第六十一层。道场的墙壁上密密麻麻的挂着一排钢刀
，不时发出阵阵“叮叮当当”的声响。道场中间有张太师椅，椅子上坐着
便是百人道场第六十一层的弟子。只见他神态若然，丝毫不感你的存在。
回眸间，你才发现他手中紧握着一把百战神刀，正发出耀眼的光芒。一股
不祥的预感油然而生，可此刻你只能有两个选择：奋身而战或退出道场。
LONG
);
	set("lvl",61);
	set("exits",([
		"east"  : __DIR__"xiuxishi",
	]));
	set("objects",([
		__DIR__"npc/dizi61":1,
	]));
	::create();
}
