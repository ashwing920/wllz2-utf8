// Room: /d/fuzhou/biaojunz.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "内宅");
	set("long", @LONG
福威镖局内宅装点的十分华贵。花梨木桌上放着一尊精致的振鬃长嘶
的玉马，右首太师椅上好大一张豹皮把整张椅子遮得严严实实。
LONG
);
	set("exits", ([
		"east"  : __DIR__"biaojuzt",
	]));
	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

