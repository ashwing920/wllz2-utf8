//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: bgschanfang.c 保国寺禅房

inherit ROOM;

void create()
{
	  set("short","保国寺禅房");
	  set("long",@LONG
这儿是保国寺内的一间禅房，布局简单，供寺内和尚诵经修行之用。
LONG);
	  set("exits",([
		"east"	: __DIR__"dxdian",
	  ]));
	  set("sleep_room", 1);

	  setup();
	  replace_program(ROOM);
}
