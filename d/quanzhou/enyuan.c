// enyuan 恩怨巷
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "恩怨巷");
	set("long", @LONG
走进巷中，就感到一股肃杀之气弥漫四周。巷旁一碑耸立，上书「恩
怨分明」四个大字，仔细一看，乃用指力刻划而成！
LONG
);

	set("exits", ([
		"south" : __DIR__"citong_e2",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
