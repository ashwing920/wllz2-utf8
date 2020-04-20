//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: /d/foshan/southgate.c

inherit ROOM;

void create()
{
	set("short","佛山南门");
	set("long",@LONG
这里是佛山镇的南门。出南门向南，就到达南海之滨了。北面一条东
西向的大街是佛山镇的主要街道。
LONG
);
	set("outdoors","foshan");
	set("exits",([ 
		"north"  : __DIR__"street3",
		"south"  : "/d/xiakedao/xkroad3",
	]));

	setup();
	replace_program(ROOM);
}

