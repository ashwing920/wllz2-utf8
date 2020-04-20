// Room: /d/wudu/hsonglin3

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","黑松林");
	set("long", @LONG
这是一片茫茫不见边的大森林，林中多有松树，遮天盖日，不见光线
故名黑松林，林中人迹罕至，毒虫出没，毒瘴迷雾，十分危险。偶尔会有
些五毒神教中的高手诡秘进出，神秘莫测。
LONG
);
	set("outdoors", "wudu");
	set("exits", ([
		"west" : __DIR__"dulongdong1",
		"southwest" : __DIR__"hsonglin4",
		"north" : __DIR__"hsonglin1",
		"east" : __DIR__"hsonglin3",
		"south" : __DIR__"hsonglin4",
	]));
	setup();
	replace_program(ROOM);

}
