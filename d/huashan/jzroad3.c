// Room: /d/huashan/jzroad3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "中条山脚");
	set("long", @LONG
你来到中条山脚。仰望天空，山势压顶，天边的红霞映透了整个山林
，呼啸的穿山风刮个不停。你不禁有些惧意。向东有一条上山小路。
LONG
);
	set("exits", ([
		"west"   : __DIR__"jzroad2",
		"eastup" : __DIR__"jzroad4",
	]));
	set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}


