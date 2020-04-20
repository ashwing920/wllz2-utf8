// Room: /d/gaibang/slandao2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "暗道");
	set("long", @LONG
这是丐帮极其秘密的地下通道，乃用丐帮几辈人之心血掘成。 
LONG
);
	set("exits", ([
		"northeast" : __DIR__"undersl",
		"southwest" : __DIR__"slandao1",
	]));
	setup();
	replace_program(ROOM);
}

