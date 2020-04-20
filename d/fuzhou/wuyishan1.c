// Room: /d/fuzhou/wuyishan1.c

inherit ROOM;

void create()
{
	set("short", "武夷山");
	set("long", @LONG
武夷山方圆两百四十里，九曲溪盘流群山之中，沿溪森列三十六峰，
碧水丹山，风光旖丽。奇峰云海，山清水秀，号称“三三水，六六峰”。
LONG
);
	set("exits", ([
		"east"  : __DIR__"fzroad2",
		"west"  : __DIR__"wuyishan2",
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

