//Room: songlin2.c 松林
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","松林");
	set("long",@LONG
这是松林深处，暗无天日，朦胧中只感觉到左右前后到处都是树影。
地上有一两个死人骷髅，发着绿荧荧的磷光。你惊骇之间，一脚踩在钢针
般的松针上！
LONG
);
	set("outdoors", "wudang");
	set("objects", ([
		CLASS_D("wudang") +"/famu": 2,
	]));
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"songlin4",
		"south"  : __DIR__"slxl2",
	]));
	setup();
	replace_program(ROOM);
}
