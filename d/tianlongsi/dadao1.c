// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆
而过。大道两旁有一些小货摊，似乎是一处集市。这条大道通向边域名城
——大理。
LONG
);
	set("outdoors", "tianlongsi");
	set("exits", ([
		"northeast": "/d/emei/qsjie2",
		"south" : __DIR__"dadao2",
	]));
	setup();
	replace_program(ROOM);
}

