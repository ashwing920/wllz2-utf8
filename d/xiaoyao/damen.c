// damen.c
// Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "石室大门");
	set("long", @LONG
穿多岩洞，突然之间，手碰到一个冷冰冰的圆物，原来是个门环，门
环的后面象是一扇铜铁铸成的大门，十分沉重。即使是臂力很好的人，推
它也觉得甚为吃力。
LONG
);
	set("exits", ([
		"north" : __DIR__"shidong",
		"south" : __DIR__"yandong",
	]));

	setup();
	replace_program(ROOM);
}
