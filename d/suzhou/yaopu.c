// Room: /d/suzhou/yaopu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "立春堂");
	set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百
个小抽屉里散发出来的。药房先生却不在店内。一名小伙计站在柜台后招
呼着顾客。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"south"  : __DIR__"dongdajie2",
	]));
	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));
	setup();
	replace_program(ROOM);
}

