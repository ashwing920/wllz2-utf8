//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: hcaeast2.c 华藏庵东廊

inherit ROOM;

void create()
{
	set("short","华藏庵东廊");
	set("long",@LONG
这里是峨嵋华藏庵东廊。走廊往南通往斋堂，北边通往广场。
LONG);
	set("outdoors", "emei");
	set("exits",([ 
		"south" : __DIR__"hcazhaitang", 
		"north" : __DIR__"hcaeast1", 
	]));

	setup();
	replace_program(ROOM);
}
