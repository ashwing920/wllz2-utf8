// shulin1.c
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这是一片茂密的树林。很多棵几十丈高的大树聚在一块，象一把把琼
天大伞，连日月都被遮蔽得暗然无光。树林中还不时可以听到大自然发出
的声响。
LONG
);
	set("exits", ([
		"north" : __DIR__"shulin/exit",
		"west" : __DIR__"xiaodao4",
	]));
	set("outdoors", "xiaoyao");

	setup();
	replace_program(ROOM);
}
