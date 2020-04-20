// Room: /d/xiangyang/juyiyuan.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "大院");
	set("long", @LONG
这里是襄阳安抚使按照郭靖、黄蓉的意思建的用来安置各地前来效力
的义士的地方。南面是一条长长的通廊，东西两边是练武场。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"east"  : __DIR__"juyilianwu1",
		"west"  : __DIR__"juyilianwu2",
		"south" : __DIR__"juyilang",
		"north" : __DIR__"westjie2",
	]));
	set("objects", ([
		__DIR__"npc/zhuziliu" : 1,
	]));
	setup();
	replace_program(ROOM);
}

