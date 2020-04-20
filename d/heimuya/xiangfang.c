// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
房内布置得十分舒适，分别摆放着几张大床，供日月教徒们休息之用。
LONG
);
	set("sleep_room",1);
	set("exits", ([
		"west" : __DIR__"pailou",
	]));
	setup();
	replace_program(ROOM);
}
