//Room: /d/dali/jianchuankou.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","剑川山口");
	set("long",@LONG
这里是苍山北麓的一个乌夷城镇。此地正处山口，两边崇山峻岭耸立
，几乎无路可行，唯有穿此镇可入苍山，因此是从蜀中至大理的军事要冲
，大理国在此修有刁楼箭塔，常年驻军。有官兵在镇口站岗巡逻，盘察过
往行人。
LONG
);
	set("objects", ([
		__DIR__"npc/jiang": 1,
		__DIR__"npc/bing": 3,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	  : __DIR__"shanlu1",
		"south"	  : __DIR__"jianchuan",
	]));
	setup();
	replace_program(ROOM);
}

