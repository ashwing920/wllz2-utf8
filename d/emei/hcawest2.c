//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: hcawest2.c 华藏庵西廊

inherit ROOM;

void create()
{
	set("short","华藏庵西廊");
	set("long",@LONG
这里是峨嵋华藏庵西廊。走廊往南禅房，北边通往广场。
LONG);
	set("outdoors", "emei");
	set("exits",([ 
		"south" : __DIR__"hcachanfang",
		"north" : __DIR__"hcawest1", 
	]));

	setup();
	replace_program(ROOM);
}
