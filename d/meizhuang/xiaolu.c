// xiaolu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "蜿蜒小径");
	set("long", @LONG
这条小路的两旁种着无数的梅花，虽然还没到梅花盛开的季节，但透
过这密密的梅林，你似乎已经闻到了阵阵的梅花的幽香，这时你已经发现
你快走到庄园的门口，你暗地里加快了脚步．
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"shijie",
		"north" : __DIR__"gate",
	]));
	set("outdoors", "meizhuang");
	setup();
	replace_program(ROOM);
}

