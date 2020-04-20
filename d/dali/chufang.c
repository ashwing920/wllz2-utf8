// Room: /d/dali/chufang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","厨房");
	set("long",@LONG
这是镇南王府的厨房，中央有个大桌子，周围则放着几个圆凳，这里
是段家弟子用餐的地方。
LONG
);
	set("objects", ([
		__DIR__"obj/xueli"	   : 4,
		__DIR__"npc/obj/puercha" : 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"east"  : __DIR__"tingfang",
	]));
	setup();
	replace_program(ROOM);
}

