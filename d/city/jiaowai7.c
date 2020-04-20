// jiaowai7.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是扬州郊外的一片芳草地，落英缤纷，蜂歌蝶舞，朝露夕光，沁人
心脾。真是踏青远足好时光。
LONG );
	set("exits", ([
		"east" : __DIR__"jiaowai6",
		"west" : __DIR__"nanmen",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}
