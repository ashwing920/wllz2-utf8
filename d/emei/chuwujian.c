//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: chuwujian.c 储物间

#include <room.h>

inherit ROOM;

void create()
{
	set("short","储物间");
	set("long",@LONG
这里便是峨嵋华藏庵的储物间，四周都是架子。一个架上放满了各样
兵器，有长剑，拂尘，长鞭等，琳琅满目。另一个架上放了各种防具。还
有一个架上摆了许多小柜子，原来是装满药品的药柜。一位师太负责管理
这里的物品，正忙碌着整理防具。后面好象有个小楼梯。门外就是斋堂了。
LONG
);
	set("objects",([
		CLASS_D("emei") + "/feng" : 1,
		__DIR__"obj/fuchen" : 1,
		__DIR__"obj/zhujian" : 1,
		__DIR__"obj/jiudai" : 1,
		__DIR__"obj/yaodai" : 1,

	]));
	set("exits",([ 
		"up"	: __DIR__"cangjingge", 
		"north" : __DIR__"hcazhaitang", 
	]));

	create_door("north", "木门", "south", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
