// Room: /d/mingjiao/sushe.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "雷门宿舍");
	set("long", @LONG
走进这间宿舍，满目异国情调。雷门教众似乎不大理睬你。许是言语
不通，你也不想在此多留。
LONG
);
	set("exits", ([
		"out" : __DIR__"mjleimen1",
	]));
	set("sleep_room", 1);
	setup();
	replace_program(ROOM);
}
