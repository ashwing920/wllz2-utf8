// TIE@FY3

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "平安道");
	set("long", @LONG
这里已经是地府最后的道路了，因为此地多是投生的人必经之路，所
以十分安静，因为如果稍有喧哗，便会再呆上十年。由此望去，远远的一
座桥，十分的雄伟。
LONG
);
	set("exits", ([
		"north" : __DIR__"wangsi",
		"south" : __DIR__"aihe",
	]) );
	set("death",1);
	setup();
	replace_program(ROOM);
}

