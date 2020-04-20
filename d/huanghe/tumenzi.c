// Room: /huanghe/tumenzi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "土门子");
	set("long", @LONG
土门子也是以前驻军的地方，周围全是沙漠，中间一块小小的绿洲，
本来这里有当地的牧民居住，可是前不就来了一伙马贼占据了这里以这
里为大本营四出劫掠，无恶不做。
LONG
);
	set("exits", ([
		"south"	 : __DIR__"wuwei",
		"northeast" : __DIR__"shixiazi",
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

