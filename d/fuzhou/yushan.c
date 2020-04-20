// Room: /d/fuzhou/wushan.c

inherit ROOM;

void create()
{
	set("short", "福州于山");
	set("long", @LONG
于山因战国时于越族在此居住而得名。相传闽越王无诸曾于九月九日
大宴于此，又称“九日山”，于山之麓的白塔，又称定光塔，系唐王审知
为了向死去的父母报恩而建。登上白塔榕城历历如画。
LONG
);
	set("exits", ([
		"northdown" : __DIR__"dongdajie",
	]));
	set("outdoors","fuzhou");
	setup();
	replace_program(ROOM);
}

