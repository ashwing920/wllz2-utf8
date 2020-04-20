// main-2f.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","不夜舫二楼");
	set("long",@LONG
沿着楼梯，你来到了不夜舫的二楼，二楼四面宽敞，只有纱帐遮挡住
楼外的风景，微风透过纱帐轻拂而来，让人感到十分舒服。二楼两边，整
齐的排列着两排红木圆桌。环顾四方，只见大堂上坐着的，都是一些衣冠
鲜艳的达官贵人，正在陪酒女的陪伴下，高声阔论，划拳喝酒，十分热闹
。西边有一扇小门，通往不夜舫的厨房。
LONG
);
	set("exits",([
		"south": __DIR__"main-2f1",
		"southdown": __DIR__"main-04",
		"west":	__DIR__"chufang",
	]));
	setup();
}