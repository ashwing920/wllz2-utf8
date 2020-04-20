//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: /d/foshan/nanling.c 南岭山口

inherit ROOM;

void create()
{
	set("short", "南岭山口");
	set("long", @LONG
这里是南岭的一个山口。南面就是佛山了，北面是横亘湖南广东的五
岭。这里地气炎热，百物速生快长，口音也远异中原了。
LONG
);
	set("outdoors", "foshan");
	set("exits", ([
		"northup" : "/d/henshan/hsroad9",
		"south"   : __DIR__"northgate",
	]));

	setup();
	replace_program(ROOM);
}

