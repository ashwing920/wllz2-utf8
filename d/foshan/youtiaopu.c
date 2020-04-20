//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: /d/foshan/youtiaopu.c

inherit ROOM;

void create()
{
	set("short","烧饼油条铺");
	set("long",@LONG
这家烧饼油条铺是新开张的。铺面不大，正中央摆了一个大炸锅和一
个烤炉。
LONG
);
	set("outdoors","foshan");
	set("exits",([
		"south"  : __DIR__"street4",
	]));

	setup();
	replace_program(ROOM);
}

