// shanlu7.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
山路崎岖，曲折蜿延。四周林木苍翠，修竹茂密。山路旁是涵碧亭，
在这里极目远眺，群山环湖尽收眼底。西边是上山的路，往东便是下山的
路。
LONG
);
	set("exits", ([
		"eastdown": __DIR__"yuhuangsj",
		"westup"  : __DIR__"yuhuangsd",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
