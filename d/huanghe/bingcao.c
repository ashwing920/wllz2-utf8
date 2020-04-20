// Room: /huanghe/bingcao.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "冰草湾");
	set("long", @LONG
冰草湾在营盘水的西南，平时人迹少至，因为当地沙漠里长着一种神
奇的药草----冰草而得名。据说这种药草能解百毒，所以偶有人来采这种
草，不过沙漠里常有毒虫出没，极为危险。
LONG
);
	set("exits", ([
		"southwest" : __DIR__"shixiazi",
		"northeast" : __DIR__"yinpanshui",
	]));
	set("objects", ([
		__DIR__"npc/wugong" : 1,
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

