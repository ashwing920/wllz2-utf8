
inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
西面是一座高山，地势极之险峻，一条窄小陡峭的山道通往山上，东
边山脚是一片长滩。
LONG
);
	set("exits",([
		"west" : __DIR__"changtan",
		"westup" : __DIR__"shandao2",
	]));
	setup();
	replace_program(ROOM);
}