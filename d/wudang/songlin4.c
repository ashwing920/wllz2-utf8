//Room: songlin4.c 松林
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
	set("objects", ([
		__DIR__"npc/xiao_louluo": 2,
	]));
	set("outdoors", "wudang");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"songlin2",
	]));
	setup();
	replace_program(ROOM);
}
