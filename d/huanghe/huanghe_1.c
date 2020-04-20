// Room: /huanghe/huanghe_1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "黄河");
	set("long", @LONG
黄河沿蒙古高原南边向东流淌，遇太行山脉的阻拦，便转头南下，形
成晋陕的分界。东北方向好象有个渡口。
LONG
);
	set("exits", ([
		"south"	 : __DIR__"weifen",
		"west"	  : __DIR__"hetao",
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

