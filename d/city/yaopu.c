// yaopu.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "药铺");
	set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百
个小抽屉里散发出来的。神医平一指坐在茶几旁，独自喝着茶，看也不看
你一眼。一名小伙计站在柜台后招呼着顾客。柜台上贴着一张发黄的广告
(guanggao)。
LONG);
	set("item_desc", ([
		"guanggao" : "本店出售以下药品：
金创药：\t五十两白银
无常丹由桃花岛黄药师所配，生死肉骨．
朱睛冰蟾救治百毒，无效包换．
其他神药与老板面议。\n",
	]));

	set("objects", ([
		__DIR__"npc/ping" : 1,
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"dongdajie2",
		"north" : __DIR__"yaopuls",
	]));
	set("no_fight",1);
	set("no_beg",1);
	setup();
	replace_program(ROOM);
}

