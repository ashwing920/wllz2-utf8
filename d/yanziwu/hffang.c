
inherit ROOM;

void create()
{
	set("short","花肥房");
	set("long",@LONG
石屋黑恫恫的, 只见一个人被绑在一根铁柱子上, 口里塞满了东西,
眼泪汪汪的, 却说不出话来。再看两旁时, 只见一个弓腰曲背的老婆子手
里拿着一柄雪亮的长刀, 身旁一锅沸水, 煮得直冒热气。
LONG);
	set("exits",([
		"east" : __DIR__"hhyuan",
		"west" : __DIR__"c13-3",
	]));
	set("objects",([
		__DIR__"npc/yan" : 1,
	]));
	setup();
	replace_program(ROOM);
}

