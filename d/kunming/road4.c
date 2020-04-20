// /d/kunming/road4

inherit ROOM;

void create()
{
	set("short","乱石滩");
	set("long", @LONG
这里怪石林立，路极不好走，不小心就要摔个跟斗，过了这片石滩，
就是长江岸边。
LONG
);
	set("outdoors", "wudang");
	set("exits", ([
		"southdown" : __DIR__"road5", 
		"northeast"  :__DIR__"road2",
	]));
	setup();
	replace_program(ROOM);
}
