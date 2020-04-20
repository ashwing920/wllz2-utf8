// TIE@FY3

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "冥府大道");
	set("long", @LONG
这里已到冥界的中心，路的两边是冥界四司，掌管人事轮回，名为忠
，孝，节，义，彰善惩恶，天理循环，到此报应，但凡来者无不前往一睹
，以警自身。
LONG
);
	set("exits", ([
		"north" : __DIR__"naihe",
		"south" : __DIR__"yanluo",
		"northwest" : __DIR__"zong",
		"southwest" : __DIR__"jie",
		"northeast" : __DIR__"xiao",
		"southeast" : __DIR__"yi",
	]) );
	set("death",1);
	setup();
	replace_program(ROOM);
}

