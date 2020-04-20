// Room: /huanghe/hetao.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "河套");
	set("long", @LONG
常言到“黄河九害，富了一套”。河套地区灌溉系统发达，土地肥沃
，是种庄稼的好地方。
LONG
);
	set("exits", ([
		"southwest" : __DIR__"huangtu",
		"east"	  : __DIR__"huanghe_1",
		"west"	  : __DIR__"qingcheng",
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

