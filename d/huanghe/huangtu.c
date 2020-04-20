// Room: /huanghe/huangtu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "黄土高原");
	set("long", @LONG
黄河像一把厉刃将黄土高原切开。无数条小溪流夹带着泥沙汇入黄河
，形成千沟万壑。沟壑之间的一块块平地叫做台塬。黄河沿蒙古高原南边
向东流淌，遇太行山脉的阻拦，便转头南下，形成晋陕的分界。
LONG
);
	set("exits", ([
		"northeast" : __DIR__"hetao",
		"southwest" : __DIR__"huanghe_2",
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

