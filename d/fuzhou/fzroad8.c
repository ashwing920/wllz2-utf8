// Room: /d/fuzhou/fzroad8.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "闽江");
	set("long", @LONG
自延福门放江而下，两岸青山夹翠，游鱼泛波，小舟穿行险滩之中，
耳畔哗哗水响，自延平到福州三百六十里水路，朝发夕至。
LONG
);
	set("exits", ([
		"northwest" : __DIR__"yanping",
		"southeast" : __DIR__"fzroad9",
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

