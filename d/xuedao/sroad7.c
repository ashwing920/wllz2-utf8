// sroad6.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","大雪山口");
	set("long",@LONG
群山环绕，四周积雪终年不化。南边不远处有一个山谷。
LONG
);
	set("exits",([
		"southdown":  __DIR__"sroad8",
		"eastdown":   __DIR__"sroad6",
	]));
	set("outdoors", "xueshan");
	setup();
	replace_program(ROOM);
}

