// xiuxis2.c 休息室

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这是一间石洞，洞内中间摆着几张大床，几张桌子，看来是个休息的
地方，室中光线柔和，使人更增睡意。
LONG );
	set("exits", ([
		"south" : __DIR__"neiting",
	]));
	set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
