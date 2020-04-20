// /d/kunming/yunnan4

inherit ROOM;

void create()
{
	set("short","原始森林");
	set("long", @LONG
走进原始森林，只见迷迷茫茫全是参天大树，遮天闭日，四周光线很
暗，分不清东南西北，任是谁进来都别想在出去了。幸好当年诸葛亮入滇
时曾开出了一条路。这里向南就走出森林了，西边则传来阵阵流水声。
LONG
);
	set("outdoors", "kunming");
	set("exits", ([
		"northeast" : __DIR__"yunnan3", 
		"south"  :__DIR__"xiaolu",
		"west"  :__DIR__"yunnan5",
	]));
	setup();
	replace_program(ROOM);
}
