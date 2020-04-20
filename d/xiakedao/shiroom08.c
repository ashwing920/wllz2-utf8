// /d/xiakedao/shiroom08.c 侠客岛 石室8

inherit ROOM;

int do_study(string arg);
void create()
{
	set("short", "石室");
	set("long", @LONG
石洞正中，一位白眉僧人和一位青袍之人正比试武功。一对男女在旁
边并肩奔行，趋退之际，步法配合甚是和谐。另有一人神色不屑地站在墙
角，边指点石壁(wall)，边指摘众人的招式。
LONG );
	set("exits", ([
		"east" : __DIR__"shihole2",
	]));
	set("item_desc", ([
		"wall" : @WALL
墙的正上方刻着「深藏身与名」几个大字。字的下方刻的是一个脍炙人口
的故事：范蠡与西施功成身退，泛舟湖上。只见图中美女星目含情，旁边
是范大夫微笑不语。舟下的水纹荡漾，与远方天色连成一体。
WALL
	]));
	set("objects", ([
		__DIR__"master/huang" : 1,
		__DIR__"master/yideng" : 1,
	]));
	set("no_fight", 1);
	set("no_beg", 1);
	setup();
}
void init()
{
	add_action("do_study","think");
}
#include "/d/xiakedao/shiroom.h"
