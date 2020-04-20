//guanwai/luming.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "鹿鸣峰");
	set("long", @LONG
龙门峰西侧就是鹿鸣峰。鹿鸣峰又称芝盘峰，因峰上有一草甸子，形
圆如盖，有热气从地下冒出，每到严冬，其它峰均积雪甚厚，唯鹿鸣峰依
然植物茂盛，且盛产芝草，鹿多居之。常有鹤、雀、雕、燕飞落其上，有
“鹿鸣翠谷，雕飞芝盖”之称。
LONG
);
	set("exits", ([
		"south"   : __DIR__"baiyun",
		"east"	: __DIR__"longmen",
	]));
	set("objects", ([
		__DIR__"npc/buck" : 1,
		__DIR__"npc/doe" : 1,
		__DIR__"npc/diao" : 1,
	]));

	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
