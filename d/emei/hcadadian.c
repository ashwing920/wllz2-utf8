//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: hcadadian.c 华藏庵大雄宝殿

#include <room.h>

inherit ROOM;

void create()
{
	set("short","华藏庵大雄宝殿");
	set("long",@LONG
这是峨嵋山华藏庵的大雄宝殿。正中供奉着普贤菩萨。一群青衣小师
太正在地上诵经。后面有道小门通往后殿。
LONG
);
	set("exits",([ 
		"northdown"  : __DIR__"hcaguangchang", 
		"south"  :__DIR__"hcahoudian"
	]));

	create_door("south", "木门", "north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
