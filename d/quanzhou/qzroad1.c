// Room: /d/quanzhou/qzroad1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com


inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一条山路上。时值春日，路旁的山坡上开满了金黄色的油菜花。
LONG
);
	set("exits", ([
		"northwest" : "/d/taishan/yidao1",
		"south" : __DIR__"qzroad2",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

