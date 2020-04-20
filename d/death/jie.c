// TIE@FY3

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "冥府节司");
	set("long", @LONG
自古以来，男女大防，节字难守，多少女子，因种种诱惑，身败名裂
，受那地狱分尸之苦。节司两旁尽是贞节女子的画像，画像中簇拥着一位
女子端坐案上，正是节司的掌管--绿珠，当年虽身为石崇侍妾，可宁死不
随他人，终跳楼而死，节烈之气，名扬千古。在其光芒之中，正受分尸之
刑的男男女女，更为丑陋。
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"naihe2",
	]) );
	set("objects", ([
		__DIR__"npc/greengirl":1,
	]) );
	set("death",1);
	setup();
	replace_program(ROOM);
}

