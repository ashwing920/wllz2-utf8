// sroad6.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","大雪山口");
	set("long",@LONG
冰天雪地，寒风刺骨。不是内力高深的人，已然经受不住了。
LONG
);
	set("exits",([
		"northdown":  __DIR__"sroad5",
		"westup":     __DIR__"sroad7",
	]));
	set("outdoors", "xueshan");
	setup();
	replace_program(ROOM);
}
