//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: xiaoshulin3.c 小树林

inherit ROOM;

void create()
{
	set("short","小树林");
	set("long",@LONG
这是峨嵋山金顶华藏庵外的一片小树林。林中没有路，但地上依稀有
些足迹，似乎刚有人走过。
LONG
);
	set("outdoors", "emei");
	set("exits",([ 
		"southeast" : __DIR__"xiaoshulin4", 
		"north"	 : __DIR__"xiaoshulin2", 
	]));

	setup();
	replace_program(ROOM);
}
