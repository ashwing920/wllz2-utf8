// mixiang.c 米仓巷
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "米仓巷");
	set("long", @LONG
这是通往粮仓的小路。由于民间匪盗经常抢劫官府粮仓，都督府震怒
之下，特开此路以利府中官兵增援粮仓。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"dufu",
		"southwest" : __DIR__"liangcang",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
