// Room: /d/gaibang/underfz.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "大榕树下");
	set("long", @LONG
这是福州大榕树下的小洞。里面破破烂烂的，丢满了各种杂物，还有
丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG
);
	set("exits", ([
		"out"	   : "/d/fuzhou/nanmendou",
		"northwest" : __DIR__"fzandao2",
	]));
	setup();
	replace_program(ROOM);
}

