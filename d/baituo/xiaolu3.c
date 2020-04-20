//xiaolu3
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long",@LONG
这里是一条上山的小路。据说最近东北方一带有山贼出没，要格外小
心。
LONG
);
	set("outdoors", "baituo");
	set("exits", ([
		"northeast" : __DIR__"xiaolu4",
		"southdown" : __DIR__"xiaolu2",
	]));
	set("objects",([
		__DIR__"npc/shanzei1" : 4,
	]));
	setup();
	replace_program(ROOM);
}
