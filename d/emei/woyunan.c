//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: woyunan.c 卧云庵

inherit ROOM;

void create()
{
	set("short","卧云庵");
	set("long",@LONG
卧云庵旁边有个井络泉，据说以前曾因饮水人多而干涸，众尼为之诵
经，于是泉水复出。出了卧云庵便是睹光台，旁边是华藏庵。
LONG
);
	set("objects", ([
		CLASS_D("emei") + "/xuan" : 1,
	]));
	set("outdoors", "emei");
	set("exits",([ 
		"out"	: __DIR__"dgtsheshenya",
		"northeast"  : __DIR__"jinding", 
		"southeast"  : __DIR__"huacangan", 
	]));
	setup();
	replace_program(ROOM);
}
