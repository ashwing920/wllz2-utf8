//Room: /d/dali/jingzhuang5.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","第五层");
	set("long",@LONG
球状，无人像，四角挂有黄铜铸灵鹫。四只灵鹫，口角噙有一枚两头
有孔的铜管，管内有金属簧片，鹫口、鹫颈、鹫腹皆是空心。每当劲风吹
来，经鹫嘴内铜管，在鹫腹内空气回旋荡扬，便发出悦耳的鸣叫。不但平
增灵鹫的神密气氛，亦可想见能工巧匠们的精湛技艺。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"up"	: __DIR__"jingzhuang6",
		"down"  : __DIR__"jingzhuang4",
	]));
	setup();
	replace_program(ROOM);
}

