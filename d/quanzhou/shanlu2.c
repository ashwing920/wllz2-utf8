// shanlu1.c 山路

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是清源山区的碎石小径，曲折蜿蜒，两旁林木茂盛，遮天蔽日。满
径落叶，柔软稀松。虫鸟啾啾。凉风习习。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"westup" : __DIR__"liandan",
		"northup" : __DIR__"huru",
		"southdown" : __DIR__"shanlu3",
	]));
	set("objects", ([
		__DIR__"npc/dog" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
