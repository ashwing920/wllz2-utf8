// Room: /d/suzhou/fengqiao.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "枫桥");
	set("long", @LONG
寺的北面有一座桥孔呈半圆的单空石桥--枫桥，她跨于运河的枫桥湾
。桥的东面是铁岭关，它与白虎关，浒墅关，合称苏州三关。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"enter" : __DIR__"hanshidian",
		"north" : __DIR__"tielingguan",
	]));
	setup();
	replace_program(ROOM);
}

