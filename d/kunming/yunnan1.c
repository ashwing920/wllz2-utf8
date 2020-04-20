// /d/kunming/yunnan

inherit ROOM;

void create()
{
	set("short","红土路");
	set("long", @LONG
进入云贵高原，泥土变为了红色，空气变得更清新，放眼看去，只见
绵绵原始森林不见边际，你顿时觉得心高志远，一股豪起涌了上来，想要
做一方大事业。
LONG
);
	set("outdoors", "kunming");
	set("exits", ([
		"south" : __DIR__"yunnan2", 
		"northeast"  :__DIR__"yunnan",
	]));
	setup();
	replace_program(ROOM);
}
