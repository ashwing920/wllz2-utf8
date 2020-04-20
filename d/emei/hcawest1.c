//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: hcawest1.c 华藏庵西廊

inherit ROOM;

void create()
{
	set("short","华藏庵西廊");
	set("long",@LONG
这里是峨嵋华藏庵西廊。走廊往南通往禅房，东边通往广场。
LONG
);
	set("outdoors", "emei");
	set("exits",([ 
		"south" : __DIR__"hcawest2",
		"east"  : __DIR__"hcaguangchang", 
	]));

	setup();
	replace_program(ROOM);
}
