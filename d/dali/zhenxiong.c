//Room: /d/dali/zhenxiong.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","镇雄");
	set("long",@LONG
这里是乌撒部的聚居中心，乌撒是乌蛮族的大部，属乌夷，领有巴的
甸、镇雄、和附近的威宁。这是一座石砌小城，人口不多，居民散居在镇
子附近，镇子上主要是一些商铺和祭祀所。
LONG
);
	set("objects", ([
		__DIR__"npc/muyangnu": 1,
		__DIR__"npc/wshangfan": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"south"	  : __DIR__"badidian",
		"north"	  : __DIR__"gelucheng",
		"northeast"  : __DIR__"minadian",
		"east"	   : __DIR__"titian1",
		"west"	   : __DIR__"wuyiminju3",
	]));
	setup();
	replace_program(ROOM);
}

