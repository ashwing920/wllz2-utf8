// jiaowai1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是扬州郊外的一片芳草地，落英缤纷，蜂歌蝶舞，朝露夕光，沁人
心脾。真是好时光。偶有几对小男女结伴踏青，莺声丽影，嬉闹动人。
LONG );

	set("exits", ([
		"north" : __DIR__"dongmen",
		"south" : __DIR__"jiaowai2",
	]));

	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}
