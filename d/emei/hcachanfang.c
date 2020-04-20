//Room: hcachanfang.c 华藏庵禅房

#include <room.h>
inherit ROOM;

void create()
{
	set("short","华藏庵禅房");
	set("long",@LONG
这里便是峨嵋华藏庵的禅房。地下散乱地放着许多蒲团，木鱼等，此
处正是本派弟子打坐修行之所。几位年轻师太和俗家女弟子正肃容入定。
禅房后面有一道门通往华藏庵休息室，北边的走廊通向广场。
LONG
);
	set("exits",([ 
		"north" : __DIR__"hcawest2", 
		"south" : __DIR__"hcaxiuxishi", 
	]));
	set("sleep_room", 1);
	create_door("south", "木门", "north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
