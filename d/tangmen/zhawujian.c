
inherit ROOM;

void create()
{
	set("short","杂物间");
	set("long",@LONG
这里是唐门的杂物间。屋内散乱的堆放着许多不知道是什么的东东。
LONG
);

	set("exits",([
		"north" : __DIR__"huayuan11",
		"east" : __DIR__"changlang16",
		"westup" : __DIR__"jiaolou5",
	]));
	set("objects", ([
		__DIR__"npc/puren" : 1,
	]));
	setup();
	replace_program(ROOM);
}




