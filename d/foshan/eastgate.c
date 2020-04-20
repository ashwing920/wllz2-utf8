//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: /d/foshan/eastgate.c


inherit ROOM;
void create()
{
	set("short","佛山东门");
	set("long",@LONG
这里是佛山镇的东门。再往东走就要离开佛山，去往福建了。西面一
条东西向的大街是佛山镇的主要街道。
LONG
);
	set("outdoors","foshan");
	set("exits",([ 
		"east"  : __DIR__"road8",
		"west"  : __DIR__"street5",
	]));

	setup();
	replace_program(ROOM);
}

