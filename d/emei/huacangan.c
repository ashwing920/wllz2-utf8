//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: huacangan.c 华藏庵

inherit ROOM;

void create()
{
	set("short","华藏庵");
	set("long",@LONG
华藏庵是金顶的主要建筑，规模宏大，中祀普贤菩萨，旁列万佛。华
藏庵后边是睹光台，旁边是卧云庵。
LONG
);
	set("outdoors", "emei");
	set("exits",([ 
		"north"	  : __DIR__"jinding",
		"northwest"  : __DIR__"woyunan", 
		"south"	  : __DIR__"duguangtai",
		"enter"	  : __DIR__"hcazhengdian",
	]));

	setup();
	replace_program(ROOM);
}
