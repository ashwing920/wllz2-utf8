// shulin10.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这位於终南山间的一大片树林，生的颇为茂密。走在其间，只听得脚
下沙沙的落叶声，四周昏昏暗暗的，不时几道日光穿过浓密的枝头，投射
而下。偶而远处几声兽吼声，更添了一份神密感。这儿也是全真教道士经
常采药的地方，往北、南各有一条小径。
LONG
);
	set("outdoors", "gumu");
	set("exits", ([
		"southup"   : __DIR__"shandao2",
		"north"     : __DIR__"shulin11",
	]));
	setup();
}
