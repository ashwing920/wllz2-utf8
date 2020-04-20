//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: hcaeast1.c 华藏庵东廊

inherit ROOM;
void create()
{
	set("short","华藏庵东廊");
	set("long",@LONG
这里是峨嵋华藏庵东廊。走廊往南通往斋堂，西边通往广场。
LONG);
	set("outdoors", "emei");
	set("exits",([ 
		"south" : __DIR__"hcaeast2", 
		"west"  : __DIR__"hcaguangchang", 
	]));

	setup();
	replace_program(ROOM);
}
