// Room: /d/wudu/caofang1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","金蛇堂");
	set("long", @LONG
这里是五毒神教的金蛇堂，墙上画着一些蛇的图腾，正中一张香桌，
上面放着一只铁盒子(hezi)，顶上垂下一盏大油灯，将这里照得明亮如昼。
LONG
);
	set("exits", ([
		"north" : __DIR__"woshi",
		"south" : __DIR__"zoulang1",
		"west"  : __DIR__"zuoxianfang",
		"east"  :__DIR__"youxianfang",
	]));
	set("objects", ([
		__DIR__"npc/nandizi" : 1,
		__DIR__"npc/nvdizi"  : 1,
	]));
	set("item_desc", ([
		"hezi" : "一只黑乎乎的盒子，不知道里面装的是什么\n",
	]));
	setup();
	replace_program(ROOM);
}



	