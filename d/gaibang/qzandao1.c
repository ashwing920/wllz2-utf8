// Room: /d/gaibang/qzandao1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "暗道");
	set("long", @LONG
这是丐帮极其秘密的地下通道，乃用丐帮几辈人之心血掘成。 
LONG
);
	set("exits", ([
		"southeast" : __DIR__"qzandao2",
		"northwest" : __DIR__"undertre",
	]));
	setup();
	replace_program(ROOM);
}

