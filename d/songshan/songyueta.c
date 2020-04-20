// Room: /d/songshan/songyueta.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "嵩岳寺塔");
	set("long", @LONG
嵩岳寺塔为密檐式砖塔，高达十余丈，外廓十二面，内室八方四门，
十五层密檐塔刹向上收紧，优美绝伦。
LONG
);
	set("exits", ([
		"east" : __DIR__"songyuesi",
	]));
	set("objects", ([
		__DIR__"npc/ding" :1,
	]));
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

