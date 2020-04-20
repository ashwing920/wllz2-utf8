// Room: /d/quanzhou/nanhu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "嘉兴南湖");
	set("long", @LONG
这里是嘉兴南湖。节近中秋，荷叶渐残，莲肉饱实。一阵轻柔婉转的
歌声，飘在烟水蒙蒙的湖面上。湖边一个道姑在一排柳树下悄立已久。
LONG
);
	set("exits", ([
		"west"	  : __DIR__"jiaxing",
		"east"	  : __DIR__"jiaxinggang",
		"south"	 : __DIR__"tieqiang",
		"southeast" : __DIR__ "nanhu1",
	]));
	set("outdoors", "quanzhou");
	set("objects", ([
		__DIR__"npc/limochou" : 1
	]));
	setup();
	replace_program(ROOM);
}

