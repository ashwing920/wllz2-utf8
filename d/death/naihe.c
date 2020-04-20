// TIE@FY3

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "冥府大道");
	set("long", @LONG
愁云惨淡之中一片安静，人来人往亦不少于人间，据说但凡能在此路
自行行走之人，都是地府中安分守己的良民，地府规矩森严更甚人间，十
八层地狱管尽天下恶人，所以此路倒还太平，安静。顺路前行便是阎宫。
LONG
);
	set("exits", ([
		"north" : __DIR__"gate",
		"south" : __DIR__"naihe2",
	]) );
	set("death",1);
	setup();
	replace_program(ROOM);
}
