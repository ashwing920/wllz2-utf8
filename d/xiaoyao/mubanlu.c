// mubanlu.c
// Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "木板路");
	set("long", @LONG
这是一条用木板铺成的小道，虽然不是很长，但是却看得出铺得十分
细心，连一些细微的疏忽也注意到了。道路两旁好种着一些奇花异树，使
过路人有心旷神怡的感觉。
LONG
);
	set("exits", ([
		"south" : __DIR__"muwu3",
		"north" : __DIR__"xiaodao4",
	]));

	set("outdoors", "xiaoyao");
	setup();
	replace_program(ROOM);
}
