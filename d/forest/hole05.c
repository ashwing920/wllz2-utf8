// /d/kunming/pubu

inherit ROOM;

void create()
{
	set("short","洞中岔路");
	set("long", @LONG
你来动洞中的深处，不知不觉，前方出现了三个岔口，分别通往山洞
中更深的地方，目睹眼前的一切，洞中究竟有何等生物，一切显得更加匪
夷所思。
LONG
);
	set("exits",([
		"northwest":	__DIR__"hole06",
		"north":	__DIR__"hole07",
		"northeast":	__DIR__"hole08",
		"south":	__DIR__"hole04",
	]));
	setup();
	replace_program(ROOM);
}
