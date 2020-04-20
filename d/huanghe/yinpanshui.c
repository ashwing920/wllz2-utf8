// Room: /huanghe/yinpanshui.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "营盘水");
	set("long", @LONG
这里是当年蒙恬修长城时驻军的地方，蒙恬治军有方，当年他亲自带
人在驻地挖了好几口甜水井，使士卒们不用喝又苦又涩的咸水，后来此地
的百姓们叫这里为营盘水，称这里的井为“蒙恬井”。
LONG
);
	set("exits", ([
		"southwest" : __DIR__"bingcao",
		"northeast" : __DIR__"guchangcheng",
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

