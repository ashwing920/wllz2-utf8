//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: /d/foshan/yingxionglou2.c

inherit ROOM;

void create()
{
	set("short","英雄楼");
	set("long",@LONG
酒楼里桌椅洁净。座中客人衣饰豪奢，十九是富商大贾。这里可以俯
瞰佛山镇全景。
LONG
);
	set("objects", ([
		__DIR__"npc/pang": 1,
		__DIR__"npc/shou": 1,
	]));
	set("exits",([
		"down"  : __DIR__"yingxionglou",
	]));
	setup();
	replace_program(ROOM);
}

