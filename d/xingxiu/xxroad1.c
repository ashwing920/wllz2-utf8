// Room: /d/xingxiu/xxroad1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
你走在一条青石大道上，尘土飞扬。东面是一座大城池，看城墙上旗
帜飘扬，好象就是长安了。西面望去一片黄土和荒野。
LONG
);
	set("exits", ([
		"east"  : "/d/city4/westgate",
		"west"  : __DIR__"xxroad2",
	]));
	set("outdoors", "xingxiuhai");
	setup();
	replace_program(ROOM);
}

