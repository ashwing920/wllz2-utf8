//Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "三岔口");
	set("long", @LONG
来到三岔口，往西南和西北方向就是日月神教石阶，山道十分陡峭。
LONG
);
	set("exits", ([ /* sizeof() == 3 */
		"westup" : __DIR__"shijie",
		"eastup" : __DIR__"suodao",
		"south" : __DIR__"meimao",
		"eastdown" : __DIR__"shandao2"
	]));
	set("outdoors","riyue");
	setup();
	replace_program(ROOM);
}
