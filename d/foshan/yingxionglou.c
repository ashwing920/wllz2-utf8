//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: /d/foshan/yingxionglou.c

inherit ROOM;

void create()
{
	set("short","英雄楼");
	set("long",@LONG
酒楼里桌椅洁净。座中客人衣饰豪奢，十九是富商大贾。佛山地处交
通要地，来这吃饭的人还真不少。
LONG
);
	set("objects", ([
		__DIR__"npc/fengqi": 1,
	]));
	set("exits",([
		"north"  : __DIR__"street4",
		"south"  : __DIR__"majiu",
		"up"	 : __DIR__"yingxionglou2",
	]));
	setup();
	replace_program(ROOM);
}

