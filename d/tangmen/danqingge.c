
inherit ROOM;

void create()
{
	set("short", "丹青阁");
	set("long", @LONG
这是花园中一座雅致的阁楼。唐门中颇多喜好舞文弄墨的弟子，常常
聚在丹青阁中交流书法、画技。阁中挂着许多画卷、书法作品。往南走是
一汪池水。
LONG
);
	set("exits", ([
		"north" : __DIR__ "huayuan2",
		"south" : __DIR__ "mochi",
	]));
	setup();
	replace_program(ROOM);
}

