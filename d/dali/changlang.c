//Room: /d/dali/changlang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","长廊");
	set("long",@LONG
这里是镇南王府的长廊，两边都是大圆柱。边上假山小湖应有尽有，
显得十分秀丽。北面是一座大建筑，南边是一个小庭院。
LONG
);
	set("objects",([
		__DIR__"npc/duanwuwei" : 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"tingfang",
		"south"  : __DIR__"tingyuan",
	]));
	setup();
	replace_program(ROOM);
}

