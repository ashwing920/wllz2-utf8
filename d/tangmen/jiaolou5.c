
inherit ROOM;

void create()
{
	set("short","角楼");
	set("long",@LONG
这是唐家堡的了望角楼。唐门虽声名显赫，势力庞大，但是也树敌不
少。为防外敌突袭，所以四周都有这样的角楼。有一队武士在这儿巡逻。
LONG
);

	set("exits",([
		"eastdown" : __DIR__"zhawujian",
	]));
	set("objects", ([
		__DIR__"npc/yaozuwushi" : 4,
	]));

	setup();
	replace_program(ROOM);
}




