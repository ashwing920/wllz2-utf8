// Room: /d/shaolin/zhonglou4.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "钟楼四层");
	set("long", @LONG
到这里楼梯大概只能容一人上下，墙身也略薄了些。视线越过窗棂，
南边的练武场，罗汉堂，般若堂历历在目，不少僧人正汇集在练武场上习
武，吆喝声一阵阵传进耳鼓。北边的藏经楼，方丈楼也尽露全貌。
LONG
);
	set("exits", ([
		"up" : __DIR__"zhonglou5",
		"down" : __DIR__"zhonglou3",
	]));
	setup();
	replace_program(ROOM);
}

