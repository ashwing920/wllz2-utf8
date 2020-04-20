// TIE@FY3

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "冥府孝司");
	set("long", @LONG
进得门来，当先坐着的竟然是位仙子般的女孩儿，正是汉时缇萦，替
父就死，虽未死，但孝道天下皆闻，两侧皆是那卧冰取鱼饷母，暖父而自
僵的孝子贤孙，殿上一块大匾，上书“孝义传家”，案下无数囚犯，正在
受油锅煎熬，都是那不孝之徒。
LONG
);
	set("exits", ([
		"southwest" : __DIR__"naihe2",
	]) );
	set("objects", ([
		__DIR__"npc/suo":1,
	]) );
	set("death",1);
	setup();
	replace_program(ROOM);
}

