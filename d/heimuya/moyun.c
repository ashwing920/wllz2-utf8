// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "卧云崖");
	set("long", @LONG
这是黑木崖的最西端卧云崖，山崖正巧高于云层一截，真有人在云上
走，云自脚下飘的雅致。
LONG
);
	set("exits", ([
		"southdown" : __DIR__"guanpu",
	]));
	set("objects", ([
		__DIR__"npc/tufei1" : 1,
		__DIR__"npc/tufei2" : 1,
	]));
	setup();
}
