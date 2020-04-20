// Room: /d/wudu/caofang1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",  "大厅" );
	set("long", @LONG
这里是五毒神教的大厅，四面墙上画满了各种奇形怪状的虫蛇图，墙
上高挂几盏油灯，忽明忽暗，显得幽森恐怖，不时有五毒神教的弟子来回
走动，五道走廊分别通向五个分堂。
LONG
);
	set("exits", ([
		"north" : __DIR__"zoulang1",
		"northeast" : __DIR__"zoulang2",
		"northwest" : __DIR__"zoulang3",
		"southeast" : __DIR__"zoulang4",
		"southwest" : __DIR__"zoulang5",
		"south" : __DIR__"qianting",
	]));
	set("valid_startroom", 1);
	setup();
}
int init()
{
	add_action("do_dig", "enter");
}
int do_dig( string arg)
{
	object me=this_player();
	if ( !arg || arg=="") return 0;
	if ( arg == "dong"){ 
	me->move(__DIR__"midao4");
	return 1;
	}
	else return 0;
}
